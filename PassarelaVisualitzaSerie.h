#pragma once
#include <iostream>
#include "ConnexioBD2.h"
using namespace std;

class PassarelaVisualitzaSerie {
	private:
		string sobrenom;
		string titolSerie;
		int numVisualitzacions;
		int numTemporada;
		int numCapitol;
		string data;

	public:
		PassarelaVisualitzaSerie() {
			sobrenom = "";
			titolSerie = "";
			numVisualitzacions = 0;
			numTemporada = 0;
			numCapitol = 0;
			data = "";
		}

		string obteSobrenom() { return sobrenom; }
		void posaSobrenom(string sobrenomS) {
			sobrenom = sobrenomS;
		}

		string obteTitolSerie() { return titolSerie; }
		void posaTitolSerie(string titolSerieS) {
			titolSerie = titolSerieS;
		}

		int obteNumVisualitzacions() { return numVisualitzacions; }
		void posaNumVisualitzacions(int numVisualitzacionsS) {
			numVisualitzacions = numVisualitzacionsS;
		}

		int obteNumTemporada() { return numTemporada; }
		void posaNumTemporada(int numTemporadaS) {
			numTemporada = numTemporadaS;
		}

		int obteNumCapitol() { return numCapitol; }
		void posaNumCapitol(int numCapitolS) {
			numCapitol = numCapitolS;
		}

		string obteData() { return data; }
		void posaData(string dataS) {
			data = dataS;
		}

		void insereix() const;

		void modifica() const;

		void esborra() const;
};

