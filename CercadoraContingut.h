#pragma once
#include <iostream>
#include "PassarelaContingut.h"
#include "ConnexioBD2.h"

using namespace std;

class CercadoraContingut {
	private:
	public:
		CercadoraContingut() {
		
		}

		PassarelaContingut cercaContingut(string titolC) {
			PassarelaContingut c;
			ConnexioBD2& con = ConnexioBD2::getInstance();
			string sql = "SELECT * FROM contingut WHERE titol = '" + titolC + "'";
			sql::ResultSet* res = con.consulta(sql);
			// Si no troba cap fila, activa excepció
			if (!res->next()) {
				throw runtime_error("Contingut no existeix");
			}
			else {
				c.posaTitol(res->getString("titol"));
				c.posaDescripcio(res->getString("descripcio"));
				c.posaQualificacio(res->getString("qualificacio"));
				c.posaTipus(res->getString("tipus"));
				delete res;
			}
			return c;
		}
};

