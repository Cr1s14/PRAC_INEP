#include "TxConsultaProperesEstrenes.h"
#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <string>
#include <memory>

void ConsultaProperesEstrenes::consulta() {
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

        // Consulta properes estrenes per la modalitat especificada
        std::unique_ptr<sql::PreparedStatement> pstmt(
            conn->prepareStatement(
                "SELECT contingut.titol, contingut.descripcio, contingut.qualificacio, contingut.tipus, "
                "       pelicula.data_estrena AS data_estrena_pelicula, pelicula.duracio, "
                "       serie.data_estrena AS data_estrena_serie "
                "FROM contingut "
                "LEFT JOIN pelicula ON contingut.titol = pelicula.titol "
                "LEFT JOIN serie ON contingut.titol = serie.titol "
                "WHERE (pelicula.data_estrena >= NOW() OR serie.data_estrena >= NOW()) "
                "AND EXISTS (SELECT 1 FROM modalitat_subscripcio WHERE nom = ?) "
                "ORDER BY COALESCE(pelicula.data_estrena, serie.data_estrena) ASC"
            )
        );
        pstmt->setString(1, modalidad);

        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        std::cout << "Properes estrenes per la modalitat: " << modalidad << "\n";
        if (!res->next()) {
            std::cout << "No hi ha continguts programats proximament.\n";
            return;
        }

        do {
            std::string titol = res->getString("titol");
            std::string descripcio = res->getString("descripcio");
            std::string qualificacio = res->getString("qualificacio");
            std::string tipus = res->getString("tipus");
            std::string dataEstrena = res->isNull("data_estrena_pelicula")
                ? res->getString("data_estrena_serie")
                : res->getString("data_estrena_pelicula");
            int duracio = res->isNull("duracio") ? 0 : res->getInt("duracio");

            std::cout << "- Titol: " << titol
                << ", Descripcio: " << descripcio
                << ", Qualificacio: " << qualificacio
                << ", Tipus: " << tipus
                << ", Data d'estrena: " << dataEstrena;

            if (tipus == "pelicula") {
                std::cout << ", Duracio: " << duracio << " minuts";
            }

            std::cout << "\n";
        } while (res->next());
    }
    catch (const sql::SQLException& e) {
        std::cerr << "Error SQL: " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

std::unique_ptr<sql::Connection> ConsultaProperesEstrenes::connectToDatabase() {
    sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
    std::unique_ptr<sql::Connection> conn(
        driver->connect("ubiwan.epsevg.upc.edu:3306", "inep08", "xubaasha8Shei6")
    );
    conn->setSchema("inep08");
    return conn;
}

