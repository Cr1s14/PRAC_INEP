#pragma once
#include <iostream>
#include "ConnexioBD2.h"
#include "PassarelaPelicula.h"
using namespace std;

class CercadoraPelicula {
	private:
	public:
		CercadoraPelicula() {

		}

		PassarelaPelicula cercaContingut(string titolP) {
			PassarelaPelicula c;
			ConnexioBD2& con = ConnexioBD2::getInstance();
			string sql = "SELECT * FROM pelicula WHERE titol = '" + titolP + "'";
			sql::ResultSet* res = con.consulta(sql);
			// Si no troba cap fila, activa excepció
			if (!res->next()) {
				throw runtime_error("Pelicula no existeix");
			}
			else {
				c.posaTitol(res->getString("titol"));
				c.posaDataEstrena(res->getString("data_estrena"));
				c.posaDuracio(res->getInt("duracio"));
				delete res;
			}
			return c;
		}
};

