#include "ConnexioBD2.h"

// Destructor: Cierra la conexi�n
ConnexioBD2::~ConnexioBD2() {
    if (con) {
        con->close();
        delete con;
    }
}

// M�todo para ejecutar comandos SQL (INSERT, DELETE, UPDATE, etc.)
void ConnexioBD2:: exec(const string query) {
    stmt = con->createStatement();
    stmt->execute(query);
    delete stmt;
}

// M�todo para realizar consultas SQL (SELECT)
sql::ResultSet* ConnexioBD2::consulta(const string query) {
    stmt = con->createStatement();
    sql::ResultSet* res = stmt->executeQuery(query);
    return res;
}