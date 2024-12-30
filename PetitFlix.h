#pragma once
#include <iostream>
#include "PassarelaUsuari.h"

class PetitFlix {

	private:
		PassarelaUsuari usuari;
		PetitFlix() {
		}

	public:
		static PetitFlix& getInstance() {
			static PetitFlix instance;
			return instance;
		}

		PassarelaUsuari obteUsuari();

		void IniciSessio(PassarelaUsuari u);

		void TancaSessio();
};

