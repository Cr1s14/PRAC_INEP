#pragma once
#include <iostream>
#include "PetitFlix.h"
#include "PassarelaUsuari.h"
#include "CercadoraVisualitzaPel.h"
#include "CercadoraVisualitzaSerie.h"
#include "PassarelaVisualitzaSerie.h"
#include "PassarelaVisualitzaPel.h"

class TxInfoVisualitzacions {

	private:
		int nP;
		int nS;

	public:
		TxInfoVisualitzacions() {
			nP = 0;
			nS = 0;
		}

		void executar();
		pair<int,int> obteResultat();
};

