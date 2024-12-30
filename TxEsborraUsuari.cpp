#include "TxEsborraUsuari.h"

void TxEsborraUsuari::executar() {
	PetitFlix& petitflix = PetitFlix::getInstance();
	PassarelaUsuari usu = petitflix.obteUsuari();
	if (usu.obteContrasenya() != contrasenyaU) {
		throw runtime_error("Contrasenya incorrecta");
	} else {
		usu.esborrar();
		Sistema& sys = Sistema::getInstance();
		sys.sessioTancada();
	}
}
