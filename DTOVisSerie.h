#pragma once
#include <iostream>

using namespace std;
class DTOVisSerie {
	private:
		string sobrenom;
		string titolSerie;
		int numVisualitzacions;
		int numTemporada;
		int numCapitol;
		string data;

	public:
		DTOVisSerie() {
			sobrenom = "";
			titolSerie = "";
			numVisualitzacions = 0;
			numTemporada = 0;
			numCapitol = 0;
			data = "";
		}

		DTOVisSerie(string sobrenomS, string titolSerieS, int numVisualitzacionsS, int numTemporadaS, int numCapitolS, string dataS) {
			sobrenom = sobrenomS;
			titolSerie = titolSerieS;
			numVisualitzacions = numVisualitzacionsS;
			numTemporada = numTemporadaS;
			numCapitol = numCapitolS;
			data = dataS;
		}

		string obteSobrenom() {
			return sobrenom;
		}

		string obteTitolSerie() {
			return titolSerie;
		}

		int obteNumVisualitzacions() {
			return numVisualitzacions;
		}

		int obteNumTemporada() {
			return numTemporada;
		}

		int obteNumCapitol() {
			return numCapitol;
		}

		string obteData() {
			return data;
		}
};

