#pragma once
#include <iostream>
#include "PetitFlix.h"
#include "PassarelaUsuari.h"
#include "Sistema.h"

using namespace std;

class TxEsborraUsuari {
	private:
		string contrasenyaU;
	
	public:
		TxEsborraUsuari() {
			contrasenyaU = "";
		}

		TxEsborraUsuari(string contraU) {
			contrasenyaU = contraU;
		}

		void executar();
};

