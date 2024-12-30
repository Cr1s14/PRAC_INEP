#pragma once
#include <iostream>
#include "ConnexioBD2.h"
#include "PassarelaVisualitzaSerie.h"

using namespace std;

class CercadoraVisualitzaSerie {
	private:
public:
	CercadoraVisualitzaSerie() {
	}
	PassarelaVisualitzaSerie cercaVisualitzacions(string sobrenom);
	PassarelaVisualitzaSerie cercaVisSerie(string sobrenom);
};

