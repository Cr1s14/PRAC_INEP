#pragma once
#include <iostream>
#include "ConnexioBD2.h"
#include "PassarelaVisualitzaPel.h"

using namespace std;

class CercadoraVisualitzaPel {
	private:
	public:
		CercadoraVisualitzaPel() {
		}
		PassarelaVisualitzaPel cercaVisualitzacions(string sobrenom);
		PassarelaVisualitzaPel cercaVisPel(string sobrenom);
};

