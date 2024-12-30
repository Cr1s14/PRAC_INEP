#pragma once
#include <iostream>
#include "CercadoraUsuari.h"
#include "PassarelaUsuari.h"
#include "PetitFlix.h"
#include "Sistema.h"

using namespace std;

class TxIniciSessio {
	private:
		string sobrenomU;
		string contrasenyaU;

	public:

		TxIniciSessio() {
			string sobrenomU = "";
			string contrasenyaU = "";
		}

		TxIniciSessio(string sU, string cU) {
			sobrenomU = sU;
			contrasenyaU = cU;
		}

		void executar() {
			CercadoraUsuari cerca;
			PassarelaUsuari u = cerca.cercaUsuari(sobrenomU);
			if (u.obteContrasenya() != contrasenyaU) {
				throw runtime_error("Contrasenya incorrecta");
			}
			else {
				PetitFlix& petitflix = PetitFlix::getInstance();
				petitflix.IniciSessio(u);
				Sistema& sys = Sistema::getInstance();
				sys.sessioIniciada();
			}
		}
};

