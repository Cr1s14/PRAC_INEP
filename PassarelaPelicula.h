#pragma once
#include <iostream>
#include <sstream>
#include "ConnexioBD2.h"
using namespace std;

class PassarelaPelicula {
	private:
		string titol;
		string dataEstrena;
		int duracio;


	public:
		PassarelaPelicula() {
			titol = "";
			dataEstrena = "";
			duracio = 0;
		}

		string obteTitol() { return titol; }
		void posaTitol(string titolC) {
			titol = titolC;
		}

		string obteDataEstrena() { return dataEstrena; }
		void posaDataEstrena(string dataEstrenaC) {
			dataEstrena = dataEstrenaC;
		}

		int obteDuracio() { return duracio; }
		void posaDuracio(int duracioC) {
			duracio = duracioC;
		}

		void insereix() {
			ConnexioBD2& con = ConnexioBD2::getInstance();
			string query = "INSERT INTO pelicula(titol, data_estrena, duracio) VALUES('" 
				+ titol + "', '"
				+ dataEstrena + "', '"
				+ to_string(duracio) + "')";
			con.exec(query);
			
		}

		void modifica() {
			ConnexioBD2& con = ConnexioBD2::getInstance();
			std::ostringstream oss;
			oss << duracio;
			string query = "UPDATE pelicula SET data_estrena = '"
				+ dataEstrena + "', duracio = '"
				+ oss.str() + "', WHERE titol = '"
				+ titol + "'";
			con.exec(query);
		}

		void esborra() {
			ConnexioBD2& con = ConnexioBD2::getInstance();
			string query = "DELETE FROM pelicula WHERE titol = '" + titol + "'";
			con.exec(query);
		}
};

