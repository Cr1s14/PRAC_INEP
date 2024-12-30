#pragma once
#include <iostream>
#include "PassarelaPelicula.h"

using namespace std;

class DTOVisPelicula {
	private:
		string sobrenom;
		string titolPelicula;
		string data;
		int numVisualitzacions;

	public:
		DTOVisPelicula() {
			sobrenom = "";
			titolPelicula = "";
			data = "";
			numVisualitzacions = 0;
		}

		DTOVisPelicula(string sobrenomP, string titolPeliculaP, string dataP, int numVisualitzacionsP) {
			sobrenom = sobrenomP;
			titolPelicula = titolPeliculaP;
			data = dataP;
			numVisualitzacions = numVisualitzacionsP;
		}
		string obteSobrenom() {
			return sobrenom;
		}

		string obteTitolPelicula() {
			return titolPelicula;
		}

		string obteData() {
			return data;
		}

		int obteNumVisualitzacions() {
			return numVisualitzacions;
		}
};

