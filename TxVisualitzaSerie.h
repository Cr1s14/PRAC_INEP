#ifndef VISUALITZARCAPITOL_H
#define VISUALITZARCAPITOL_H

#include <string>
#include <memory>
#include <cppconn/connection.h>
#include "PetitFlix.h"
#include "PassarelaUsuari.h"

class VisualitzarCapitol {
public:
     void visualitzar();
     VisualitzarCapitol() {
         nomSerie = "";
     }

    VisualitzarCapitol(std::string nomSerieC) {
         nomSerie = nomSerieC;
     }
private:
    std::string nomSerie;
     std::unique_ptr<sql::Connection> connectToDatabase();
     bool getSerieDetails(sql::Connection* conn, const std::string& sobrenomUsuari, const std::string& nomSerie);
     bool isAgeAppropriate(sql::Connection* conn, const std::string& sobrenomUsuari, const std::string& qualificacio);
     int getTemporades(sql::Connection* conn, const std::string& nomSerie);
     int seleccionarTemporada(int numTemporades);
     void mostrarCapitols(sql::Connection* conn, const std::string& sobrenomUsuari, const std::string& nomSerie, int temporadaSeleccionada);
     void registrarVisualitzacio(sql::Connection* conn, const std::string& sobrenomUsuari, const std::string& nomSerie, int temporada, int capitol);
};

#endif 

