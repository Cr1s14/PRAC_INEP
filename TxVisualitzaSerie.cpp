#include "TxVisualitzaSerie.h"
#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <memory>
#include <string>

using namespace std;


void VisualitzarCapitol::visualitzar() {
    PetitFlix& petitflix = PetitFlix::getInstance();
    PassarelaUsuari p = petitflix.obteUsuari();
    string sobrenomUsuari = p.obteSobrenom();
    try {
        // Establir conexió amb la base de dades
        auto conn = connectToDatabase();

        // Verificar detalls de la serie
        if (!getSerieDetails(conn.get(), sobrenomUsuari, nomSerie)) {
            return;
        }

        // Obtenir número de temporadas disponibles
        int numTemporades = getTemporades(conn.get(), nomSerie);
        if (numTemporades == 0) {
            std::cout << "Error: No hi ha temporades disponibles per a aquesta serie.\n";
            return;
        }

        // Solicitar a l'usuario seleccionar una temporada
        int temporadaSeleccionada = seleccionarTemporada(numTemporades);

        // Mostrar i seleccionar capítulos de la temporada
        mostrarCapitols(conn.get(), sobrenomUsuari, nomSerie, temporadaSeleccionada);
    }
    catch (const sql::SQLException& e) {
        std::cerr << "Error SQL: " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

std::unique_ptr<sql::Connection> VisualitzarCapitol::connectToDatabase() {
    sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
    std::unique_ptr<sql::Connection> conn(
        driver->connect("ubiwan.epsevg.upc.edu:3306", "inep08", "xubaasha8Shei6")
    );
    conn->setSchema("inep08");
    return conn;
}

bool VisualitzarCapitol::getSerieDetails(sql::Connection* conn, const std::string& sobrenomUsuari, const std::string& nomSerie) {
    std::unique_ptr<sql::PreparedStatement> pstmt(
        conn->prepareStatement(
            "SELECT qualificacio FROM contingut WHERE titol = ? AND tipus = 'serie'"
        )
    );
    pstmt->setString(1, nomSerie);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
    if (!res->next()) {
        std::cout << "Error: La serie no existeix.\n";
        return false;
    }

    std::string qualificacio = res->getString("qualificacio");
    if (!isAgeAppropriate(conn, sobrenomUsuari, qualificacio)) {
        std::cout << "Error: La serie no es adequada per a la teva edat.\n";
        return false;
    }

    return true;
}

bool VisualitzarCapitol::isAgeAppropriate(sql::Connection* conn, const std::string& sobrenomUsuari, const std::string& qualificacio) {
    std::unique_ptr<sql::PreparedStatement> pstmt(
        conn->prepareStatement("SELECT YEAR (data_naixement) AS any_naixement FROM usuari WHERE sobrenom = ?")
    );
    pstmt->setString(1, sobrenomUsuari);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
    if (res->next()) {
        int anyUsuari = res->getInt("any_naixement");
        // Validar edad segons la calificació
        int edat = 2024 - anyUsuari;
        int edatMinima = std::stoi(qualificacio.substr(0, qualificacio.find('+')));
        return edat >= edatMinima;
    }

    return false;
}

int VisualitzarCapitol::getTemporades(sql::Connection* conn, const std::string& nomSerie) {
    std::unique_ptr<sql::PreparedStatement> pstmt(
        conn->prepareStatement(
            "SELECT COUNT(*) AS num_temporades FROM temporada WHERE titol_serie = ?"
        )
    );
    pstmt->setString(1, nomSerie);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
    if (res->next()) {
        return res->getInt("num_temporades");
    }

    return 0;
}

int VisualitzarCapitol::seleccionarTemporada(int numTemporades) {
    int temporadaSeleccionada = 0;

    do {
        std::cout << "Introdueix el numero de temporada (1-" << numTemporades << "): ";
        std::cin >> temporadaSeleccionada;
    } while (temporadaSeleccionada < 1 || temporadaSeleccionada > numTemporades);

    return temporadaSeleccionada;
}

void VisualitzarCapitol::mostrarCapitols(sql::Connection* conn, const std::string& sobrenomUsuari, const std::string& nomSerie, int temporadaSeleccionada) {
    std::unique_ptr<sql::PreparedStatement> pstmt(
        conn->prepareStatement(
            "SELECT numero, titol, data_estrena, "
            "IFNULL((SELECT data FROM visualitzacio_capitol "
            "WHERE sobrenom_usuari = ? AND titol_serie = ? AND numero_temporada = ? AND numero = cap.numero), 'No visualitzat') AS estat_visualitzacio "
            "FROM capitol cap WHERE titol_serie = ? AND numero_temporada = ?"
        )
    );
    pstmt->setString(1, sobrenomUsuari);
    pstmt->setString(2, nomSerie);
    pstmt->setInt(3, temporadaSeleccionada);
    pstmt->setString(4, nomSerie);
    pstmt->setInt(5, temporadaSeleccionada);

    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    std::cout << "Capitols de la temporada " << temporadaSeleccionada << ":\n";
    while (res->next()) {
        std::cout << "Capitol " << res->getInt("numero") << ": " << res->getString("titol")
            << ", Data d'estrena: " << res->getString("data_estrena")
            << ", Estat: " << res->getString("estat_visualitzacio") << "\n";
    }

    // Solicitar capítul
    int numCapitol;
    std::cout << "Introdueix el numero de capitol per visualitzar: ";
    std::cin >> numCapitol;

    // Confirmar visualizació
    std::cout << "Vols visualitzar aquest capitol? (S/N): ";
    char confirmacio;
    std::cin >> confirmacio;

    if (confirmacio == 'S' || confirmacio == 's') {
        registrarVisualitzacio(conn, sobrenomUsuari, nomSerie, temporadaSeleccionada, numCapitol);
        std::cout << "Visualitzacio registrada amb exit.\n";
    }
    else {
        std::cout << "Visualitzacio cancelada.\n";
    }
}

void VisualitzarCapitol::registrarVisualitzacio(sql::Connection* conn, const std::string& sobrenomUsuari, const std::string& nomSerie, int temporada, int capitol) {
    std::unique_ptr<sql::PreparedStatement> pstmt(
        conn->prepareStatement(
            "INSERT INTO visualitzacio_capitol (sobrenom_usuari, titol_serie, num_temporada, num_capitol, data, num_visualitzacions) "
            "VALUES (?, ?, ?, ?, NOW(), 1) ON DUPLICATE KEY UPDATE num_visualitzacions = num_visualitzacions + 1"
        )
    );
    pstmt->setString(1, sobrenomUsuari);
    pstmt->setString(2, nomSerie);
    pstmt->setInt(3, temporada);
    pstmt->setInt(4, capitol);
    pstmt->executeUpdate();
}
