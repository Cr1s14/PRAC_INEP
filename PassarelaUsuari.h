#ifndef PASSARELAUSUARI_H
#define PASSARELAUSUARI_H

#include <iostream>
#include "ConnexioBD2.h"

using namespace std;

class PassarelaUsuari {
	private:
		string sobrenom;
		string nom;
		string contrasenya;
		string correuElectronic;
		string dataNaixement;
		string modalitatsubscripcio;

	public:
			PassarelaUsuari();	
			
			PassarelaUsuari(string sobrenomU, string nomU, string correuElectronicU, string contrasenyaU, string dataNaixementU, string subscripcioU);

			string obteSobrenom();
			void posaSobrenom(string sobrenomU) {
				sobrenom = sobrenomU;
			}

			string obteNom();
			void posaNom(string nomU) {
				nom = nomU;
			}

			string obteCorreuElectronic();
			void posaCorreuElectronic(string correuU) {
				correuElectronic = correuU;
			}
				
			string obteContrasenya();
			void posaContrasenya(string contrasenyaU) {
				contrasenya = contrasenyaU;
			}

			string obteDataNaixement();
			void posaDataNaixement(string dataU) {
				dataNaixement = dataU;	
			}

			string obteSubscripcio();
			void posaSubscripcio(string subscripcioU) {
				modalitatsubscripcio = subscripcioU;
			}

			void insereix() const;

			void esborrar() const;

			void modifica() const;
};

#endif