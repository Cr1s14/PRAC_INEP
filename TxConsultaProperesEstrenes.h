#ifndef CONSULTAPROPERESSTRENES_H
#define CONSULTAPROPERESSTRENES_H

#include <string>
#include <memory>
#include <cppconn/connection.h>
#include "PetitFlix.h"
#include "Sistema.h"

class ConsultaProperesEstrenes {
public:
    void consulta();

private:
    std::string modalidad;
    std::unique_ptr<sql::Connection> connectToDatabase();
};

#endif

