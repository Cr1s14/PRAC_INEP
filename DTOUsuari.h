#ifndef DTOUSUARI_H
#define DTOUSUARI_H

#include "PassarelaUsuari.h"

class DTOUsuari {
public:
	DTOUsuari() {
		string nom = "";
		string sobrenom = "";
		string correuElectronic = "";
		string dataNaixement = "";
		string modalitat = "";
	}

	DTOUsuari(string nomU,string sobrenomU,string correuU, string dataNeixU, string modalitatU) {
		nom = nomU;
		sobrenom = sobrenomU;
		correuElectronic = correuU;
		dataNaixement = dataNeixU;	
		modalitat = modalitatU;
	}

	string obteSobrenom() { return sobrenom; }
	string obteNom() { return nom; }
	string obteCorreu() { return correuElectronic; }
	string obteDataNaixement() { return dataNaixement; }
	string obteSubscripcio() { return modalitat; }

private:
	string nom = "";
	string sobrenom = "";
	string correuElectronic = "";
	string dataNaixement = "";
	string modalitat = "";
};

#endif