#include "CtrlModificaUsuari.h"

DTOUsuari CtrlModificaUsuari::consultaUsuari() {
	TxConsultaUsuari tx;
	tx.executar();
	DTOUsuari infoUsu = tx.obteResultat();
	usuari = tx.obteUsuari();
	return infoUsu;
}

void CtrlModificaUsuari::modificaUsuari(string nomU, string contraU, string correuU, string neixU, string modalitatU) {
	if (!nomU.empty()) {
		usuari.posaNom(nomU);
	} 
	if (!contraU.empty()) {
		usuari.posaContrasenya(contraU);
	}
	if (!correuU.empty()) {
		usuari.posaCorreuElectronic(correuU);
	}
	if (!neixU.empty()) {
		usuari.posaDataNaixement(neixU);
	}
	if (!modalitatU.empty()) {
		usuari.posaSubscripcio(modalitatU);
	}

	usuari.modifica();

	PetitFlix& petitflix = PetitFlix::getInstance();
	petitflix.IniciSessio(usuari);
}
