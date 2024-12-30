#include "TxConsultaUsuari.h"

void TxConsultaUsuari::executar() { 
	string nomU, sobrenomU, correuU, dataNeixU, modalitatU;
	PetitFlix &petitflix = PetitFlix::getInstance();
	usuari = petitflix.obteUsuari();

	nomU = usuari.obteNom();
	sobrenomU = usuari.obteSobrenom();	
	correuU = usuari.obteCorreuElectronic();
	dataNeixU = usuari.obteDataNaixement();	
	modalitatU = usuari.obteSubscripcio();	

	DTOUsuari res(nomU, sobrenomU, correuU, dataNeixU, modalitatU);
	resultat = res;
}

DTOUsuari TxConsultaUsuari::obteResultat() {
	DTOUsuari infoUsuari = resultat;
	return infoUsuari;
}

PassarelaUsuari TxConsultaUsuari::obteUsuari() {
	PassarelaUsuari u = usuari;
	return u;
}