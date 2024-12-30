#include "ConnexioBD2.h"

// Destructor: Cierra la conexión
ConnexioBD2::~ConnexioBD2() {
    if (con) {
        con->close();
        delete con;
    }
}

// Método para ejecutar comandos SQL (INSERT, DELETE, UPDATE, etc.)
void ConnexioBD2:: exec(const string query) {
    stmt = con->createStatement();
    stmt->execute(query);
    delete stmt;
}

// Método para realizar consultas SQL (SELECT)
sql::ResultSet* ConnexioBD2::consulta(const string query) {
    stmt = con->createStatement();
    sql::ResultSet* res = stmt->executeQuery(query);
    return res;
}