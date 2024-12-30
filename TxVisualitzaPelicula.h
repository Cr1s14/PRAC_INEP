#ifndef VISUALITZARPELICULA_H
#define VISUALITZARPELICULA_H

#include <string>
#include <memory>
#include <cppconn/connection.h>
#include <locale>
#include "PetitFlix.h"
#include "PassarelaUsuari.h"
class VisualitzarPelicula {
public:
    void visualitzar();
    VisualitzarPelicula() {
        nomPelicula = "";
    }
    VisualitzarPelicula(string nomP) {
        nomPelicula = nomP;
    }

private:
    std::string nomPelicula;
     std::unique_ptr<sql::Connection> connectToDatabase();
     void registrarVisualitzacio(sql::Connection* conn, const std::string& sobrenomUsuari, const std::string& nomPelicula);
     void mostrarRelacionades(sql::Connection* conn, const std::string& nomPelicula);
};

#endif

