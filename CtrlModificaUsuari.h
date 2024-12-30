#pragma once
#include <iostream>
#include "PassarelaUsuari.h"
#include "DTOUsuari.h"
#include "TxConsultaUsuari.h"
#include "PetitFlix.h"

class CtrlModificaUsuari {
	private:
		PassarelaUsuari usuari;
public:
	CtrlModificaUsuari() {
	}
	void modificaUsuari(string nomU, string contraU, string correuU, string neixU, string subsU);
	DTOUsuari consultaUsuari();
};

