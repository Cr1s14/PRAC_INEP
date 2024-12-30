#pragma once
#include <iostream>
#include "ConnexioBD2.h"

using namespace std;

class PassarelaVisualitzaPel {
	private:
		string sobrenom;
		string titolPelicula;
		string data;
		int numVisualitzacions;

	public:
		PassarelaVisualitzaPel() {
			sobrenom = "";
			titolPelicula = "";
			data = "";
			numVisualitzacions = 0;
		}

		string obteSobrenom() { return sobrenom; }
		void posaSobrenom(string sobrenomP) {
			sobrenom = sobrenomP;
		}

		string obteTitolPelicula() { return titolPelicula; }
		void posaTitolPelicula(string titolPeliculaP) {
			titolPelicula = titolPeliculaP;
		}

		string obteData() { return data; }
		void posaData(string dataP) {
			data = dataP;
		}

		int obteNumVisualitzacions() { return numVisualitzacions; }
		void posaNumVisualitzacions(int numVisualitzacionsP) {
			numVisualitzacions = numVisualitzacionsP;
		}

		void insereix() const;

		void modifica() const;

		void esborra() const;
};

