#ifndef CONSULTAULTIMESNOVETATS_H
#define CONSULTAULTIMESNOVETATS_H

#include <string>
#include <memory>
#include <cppconn/connection.h>
#include "PetitFlix.h"

class ConsultaUltimesNovetats {
public:
    void consulta();

private:
    std::string modalidad = "";
    std::unique_ptr<sql::Connection> connectToDatabase();
};

#endif