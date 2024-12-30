#include "TxConsultaUltimesNovetats.h"
#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <string>
#include <memory>

void ConsultaUltimesNovetats::consulta() {
    PetitFlix& petitflix = PetitFlix::getInstance();
    PassarelaUsuari pU = petitflix.obteUsuari();
    std::string modalidad = pU.obteSubscripcio();
    if (modalidad.empty()) {
        std::cout << "Modalitats de subscripcio disponibles" << std::endl;
        std::cout << " > 1. Completa" << std::endl;
        std::cout << " > 2. Cinefil" << std::endl;
        std::cout << " > 3. Infantil" << std::endl;
        std::cout << "Escull modalitat: ";

        int opciosubscripcioU;
        std::cin >> opciosubscripcioU;

        switch (opciosubscripcioU) {
        case 1:
            modalidad = "Completa";
            break;
        case 2:
            modalidad = "Cinefil";
            break;
        case 3:
            modalidad = "Infantil";
            break;
        default:
            std::cout << "Modalitat no existeix" << std::endl;
            return;
        }
    }
    try {
        auto conn = connectToDatabase();

        // Consultar últimes pel·lícules estrenades
        std::cout << "Ultimes pelicules estrenades:\n";
        std::unique_ptr<sql::PreparedStatement> pstmtPeliculas(
            conn->prepareStatement(
                "SELECT pelicula.data_estrena, pelicula.titol, qualificacio, duracio "
                "FROM pelicula INNER JOIN contingut ON pelicula.titol = contingut.titol "
                "WHERE contingut.tipus = 'pelicula' "
                "AND EXISTS (SELECT 1 FROM modalitat_subscripcio WHERE nom = ?) "
                "ORDER BY pelicula.data_estrena DESC LIMIT 5"
            )
        );
        pstmtPeliculas->setString(1, modalidad);

        std::unique_ptr<sql::ResultSet> resPeliculas(pstmtPeliculas->executeQuery());
        if (!resPeliculas->next()) {
            std::cout << "No hi ha pelicules recentment estrenades.\n";
        }
        else {
            do {
                std::cout << "- Data: " << resPeliculas->getString("data_estrena")
                    << ", Titol: " << resPeliculas->getString("titol")
                    << ", Qualificacio: " << resPeliculas->getString("qualificacio")
                    << ", Duracio: " << resPeliculas->getInt("duracio") << " minuts\n";
            } while (resPeliculas->next());
        }

        // Consultar últimes sèries estrenades
        std::cout << "\nUltimes series estrenades:\n";
        std::unique_ptr<sql::PreparedStatement> pstmtSeries(
            conn->prepareStatement(
                "SELECT MAX(cap.data_estrena) AS data_estrena, cap.titol_serie, contingut.qualificacio "
                "FROM capitol cap "
                "INNER JOIN contingut ON cap.titol_serie = contingut.titol "
                "WHERE EXISTS (SELECT 1 FROM modalitat_subscripcio WHERE nom = ?) "
                "GROUP BY cap.titol_serie, contingut.qualificacio "
                "ORDER BY data_estrena DESC LIMIT 5"
            )
        );
        pstmtSeries->setString(1, modalidad);

        std::unique_ptr<sql::ResultSet> resSeries(pstmtSeries->executeQuery());
        if (!resSeries->next()) {
            std::cout << "No hi ha series recentment estrenades.\n";
        }
        else {
            do {
                std::cout << "- Data: " << resSeries->getString("data_estrena")
                    << ", Serie: " << resSeries->getString("titol_serie")
                    << ", Qualificacio: " << resSeries->getString("qualificacio") << "\n";
            } while (resSeries->next());
        }

    }
    catch (const sql::SQLException& e) {
        std::cerr << "Error SQL: " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

std::unique_ptr<sql::Connection> ConsultaUltimesNovetats::connectToDatabase() {
    sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
    std::unique_ptr<sql::Connection> conn(
        driver->connect("ubiwan.epsevg.upc.edu:3306", "inep08", "xubaasha8Shei6")
    );
    conn->setSchema("inep08");
    return conn;
}