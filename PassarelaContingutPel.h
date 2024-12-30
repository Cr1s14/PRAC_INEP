#pragma once
#include <iostream>
using namespace std;

class DTOContingutPel {
	private:
		string titol;
		string qualificacio;
		int duracio;
		int numVisualitzacions;
		string vista;
	public:
		DTOContingutPel() {
			titol = "";
			qualificacio = "";
			duracio = 0 ;
			numVisualitzacions = 0;
			vista = "";
		}

		DTOContingutPel(string titolC, string qualificacioC, int duracioC, int numVisualitzacionsC,string vistaC) {
			titol = titolC;
			qualificacio = qualificacioC;
			duracio = duracioC;
			numVisualitzacions = numVisualitzacionsC;
			vista = vistaC;
		}
		string obteTitol() {
			return titol;
		}

		string obtequalificacio() {
			return qualificacio;
		}

		int obteDuracio() {
			return duracio;
		}

		int obteNumVisualitzacions() {
			return numVisualitzacions;
		}

		string obteVista() {
			return vista;
		}
};

