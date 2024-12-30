#pragma once
#include <iostream>

using namespace std;

class DTOContingut {
	private:
		string titol;
		string descripcio;
		string qualificacio;
		string tipus;

	public:
		DTOContingut() {
			titol = "";
			descripcio = "";
			qualificacio = "";
			tipus = "";
		}

		DTOContingut(string titolC, string descripcioC, string qualificacioC, string tipusC) {
			titol = titolC;
			descripcio = descripcioC;
			qualificacio = qualificacioC;
			tipus = tipusC;
		}

		string obteTitol() {
			return titol;
		}
		string obteDescripcio() {
			return descripcio;
		}
		string obteQualificacio() {
			return qualificacio;
		}
		string obteTipus() {
			return tipus;
		}
};

