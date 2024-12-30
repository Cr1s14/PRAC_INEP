#pragma once
#include <iostream>
#include "ConnexioBD2.h"
#include <sstream>
using namespace std;

class PassarelaContingut {
	private:
		string titol;
		string descripcio;
		string qualificacio;
		string tipus;

	public:
		PassarelaContingut() {
			titol = "";
			descripcio = "";
			qualificacio = "";
			tipus = "";

		}

		string obteTitol() { return titol; }
		void posaTitol(string titolC) {
			titol = titolC;
		}

		string obteDescripcio() { return descripcio; }
		void posaDescripcio(string descripcioC) {
			descripcio = descripcioC;
		}

		string obteQualificacio() { return qualificacio; }
		void posaQualificacio(string qualificacioC) {
			qualificacio = qualificacioC;
		}

		string obteTipus() { return tipus; }
		void posaTipus(string tipusC) {
			tipus = tipusC;
		}

		void insereix() {
			ConnexioBD2& con = ConnexioBD2::getInstance();
			std::ostringstream oss;
			oss << qualificacio;
			string query = "INSERT INTO contingut(titol, descripcio, qualificacio,tipus) VALUES('"
				+ titol + "', '"
				+ descripcio + "', '"
				+ oss.str() + "','"
				+ tipus + "')";
			con.exec(query);
		
		}

		void modifica() {
			ConnexioBD2& con = ConnexioBD2::getInstance();
			string query = "UPDATE contingut SET descripcio = '"
				+ descripcio + "', qualificacio = '"
				+ qualificacio + "', tipus='" 
				+ tipus + "', WHERE titol = '"
				+ titol + "'";
			con.exec(query);
		
		}
		void esborra() {
			ConnexioBD2& con = ConnexioBD2::getInstance();
			string query = "DELETE FROM contingut WHERE titol = '" + titol + "'";
			con.exec(query);
		
		}
};

