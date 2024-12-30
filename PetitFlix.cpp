#include "PetitFlix.h"


PassarelaUsuari PetitFlix::obteUsuari() {
	PassarelaUsuari u = usuari;
	return u;
}

void PetitFlix::IniciSessio(PassarelaUsuari u) {
	usuari = u;
}

void PetitFlix::TancaSessio() {
	usuari = PassarelaUsuari();
}
