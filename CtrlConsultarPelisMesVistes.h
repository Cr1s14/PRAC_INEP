#pragma once
#include <iostream>
#include "ConnexioBD2.h"
#include "TxConsultaPeli.h"
#include "PassarelaPelicula.h"
#include "DTOPelicula.h"
#include "PassarelaContingutPel.h"
#include "PassarelaPelicula.h"
#include "PassarelaContingut.h"
#include <vector>
#include "CercadoraPelicula.h"
#include "CercadoraContingut.h"

using namespace std;
class CtrlConsultarPelisMesVistes {
	private:
		vector<DTOContingutPel> con_pel;
		int pos = 0;

	public:
		CtrlConsultarPelisMesVistes() {
		
		}

		void executar() {
			ConnexioBD2& con = ConnexioBD2::getInstance();
			string query = "SELECT sobrenom_usuari, titol_pelicula, data, SUM(num_visualitzacions) AS num_visualitzacions  FROM visualitzacio_pelicula  GROUP BY titol_pelicula  ORDER BY num_visualitzacions DESC  LIMIT 5";
			sql::ResultSet* res = con.consulta(query);
			if (!res->next()) {
				throw runtime_error("Pelicula no existeix");
			}
			else {
				do {
					string titol = (res->getString("titol_pelicula"));
					string data = (res->getString("data"));
					int visualitzacions = (res->getInt("num_visualitzacions"));
					CercadoraContingut cerca;
					CercadoraPelicula cerca2;

					PassarelaContingut contingut = cerca.cercaContingut(titol);
					PassarelaPelicula pelicula = cerca2.cercaContingut(titol);
					DTOContingutPel pel(titol, contingut.obteQualificacio(), pelicula.obteDuracio(), visualitzacions, data);
					con_pel.push_back(pel);
				} while (res->next());

			}
		}

		DTOContingutPel obteContingutPelicula() {
			DTOContingutPel pelicula = con_pel[pos];
			++pos;
			return pelicula;
		}
};

