#pragma once
#include <iostream>
#include "PassarelaUsuari.h"

using namespace std;

class TxRegistraUsuari {
	private:
		string nomU;
		string sobrenomU;
		string contrasenyaU;
		string correuElectronicU;
		string dataNaixementU;
		string modalitatSubscripcioU;


	public:
		TxRegistraUsuari() {
			string nomU = "";
			string sobrenomU = "";
			string contrasenyaU = "";
			string correuElectronicU = "";
			string dataNaixementU = "";
			string modalitatSubscripcioU = "";
		}

		TxRegistraUsuari(string sU, string nU, string cU, string ceU, string dnU, string msU) {
			nomU = nU;
			sobrenomU = sU;
			contrasenyaU = cU;
			correuElectronicU = ceU;
			dataNaixementU = dnU;
			modalitatSubscripcioU = msU;
		}

		void executar() {
			PassarelaUsuari usuari(sobrenomU, nomU, contrasenyaU, correuElectronicU, dataNaixementU, modalitatSubscripcioU);
			usuari.insereix();
		}
};

