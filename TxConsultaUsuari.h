#pragma once

#include <iostream>
#include "DTOUsuari.h"
#include "PassarelaUsuari.h"
#include "PetitFlix.h"

class TxConsultaUsuari {
	private:
		DTOUsuari resultat;
		PassarelaUsuari usuari;
	public:
		TxConsultaUsuari() {
		}

		void executar();

		DTOUsuari obteResultat();

		PassarelaUsuari obteUsuari();
};

