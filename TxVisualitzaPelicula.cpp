#include "TxVisualitzaPelicula.h"
#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <string>
#include <memory>

using namespace std;

void VisualitzarPelicula::visualitzar() {
    
    PetitFlix& petitflix = PetitFlix::getInstance();
    PassarelaUsuari p = petitflix.obteUsuari();
    std::string sobrenomUsuari = p.obteSobrenom();

    try {
        // Establir conexió amb la base de dades
        auto conn = connectToDatabase();

        // Obtenir detalls de la pel·lícula
        std::unique_ptr<sql::PreparedStatement> pstmt(
            conn->prepareStatement("SELECT descripcio, qualificacio, duracio, data_estrena "
                "FROM pelicula INNER JOIN contingut ON pelicula.titol = contingut.titol "
                "WHERE pelicula.titol = ?")
        );
        pstmt->setString(1, nomPelicula);

        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        if (!res->next()) {
            std::cout << "Error: La pel·licula no existeix.\n";
            return;
        }

        // Mostrar detalles de la pel·lícula
        std::string descripcio = res->getString("descripcio");
        std::string qualificacio = res->getString("qualificacio");
        int duracio = res->getInt("duracio");
        std::string dataEstrena = res->getString("data_estrena");

        cout << "Detalls de la pelicula:\n"
            << "Descripcio: " << descripcio << "\n"
            << "Qualificacio per edats: " << qualificacio << "\n"
            << "Duracio: " << duracio << " minuts\n"
            << "Data d'estrena: " << dataEstrena << "\n";

        // Confirmar visualizació
        std::cout << "Vols visualitzar aquesta pelicula? (S/N): ";
        char confirmacio;
        std::cin >> confirmacio;

        if (confirmacio != 'S' && confirmacio != 's') {
            std::cout << "Visualitzacio cancel·lada.\n";
            return;
        }

        // Registrar visualizació
        registrarVisualitzacio(conn.get(), sobrenomUsuari, nomPelicula);

        // Mostrar pel·lículas relacionades
        mostrarRelacionades(conn.get(), nomPelicula);
    }
    catch (const sql::SQLException& e) {
        std::cerr << "Error SQL: " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

std::unique_ptr<sql::Connection> VisualitzarPelicula::connectToDatabase() {
    sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
    std::unique_ptr<sql::Connection> conn(
        driver->connect("ubiwan.epsevg.upc.edu:3306", "inep08", "xubaasha8Shei6")
    );
    conn->setSchema("inep08");
    return conn;
}

void VisualitzarPelicula::registrarVisualitzacio(sql::Connection* conn, const std::string& sobrenomUsuari, const std::string& nomPelicula) {
    std::unique_ptr<sql::PreparedStatement> pstmt(
        conn->prepareStatement(
            "INSERT INTO visualitzacio_pelicula (sobrenom_usuari, titol_pelicula, data, num_visualitzacions) "
            "VALUES (?, ?, NOW(), 1) ON DUPLICATE KEY UPDATE num_visualitzacions = num_visualitzacions + 1"
        )
    );
    pstmt->setString(1, sobrenomUsuari);
    pstmt->setString(2, nomPelicula);
    pstmt->executeUpdate();

    std::cout << "Visualitzacio registrada amb exit.\n";
}

void VisualitzarPelicula::mostrarRelacionades(sql::Connection* conn, const std::string& nomPelicula) {
    std::unique_ptr<sql::PreparedStatement> pstmt(
        conn->prepareStatement(
            "SELECT c.titol, c.descripcio, c.qualificacio, p.duracio, p.data_estrena "
            "FROM relacionat r "
            "INNER JOIN contingut c ON r.titol_y = c.titol "
            "INNER JOIN pelicula p ON c.titol = p.titol "
            "WHERE r.titol_x = ? "
            "ORDER BY p.data_estrena DESC"
        )
    );
    pstmt->setString(1, nomPelicula);
    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    while (res->next()) {
        std::cout << "Pelicules relacionades:\n";
        std::cout << "Títol: " << res->getString("titol") << ", Descripció: " << res->getString("descripcio")
            << ", Qualificació: " << res->getString("qualificacio")
            << ", Duració: " << res->getInt("duracio")
            << ", Data d'estrena: " << res->getString("data_estrena") << "\n";
    }
}