#include "PassarelaUsuari.h"

PassarelaUsuari::PassarelaUsuari() {
	sobrenom = "";
	nom = "";
	correuElectronic = "";
	contrasenya = "";
	dataNaixement = "";
	modalitatsubscripcio = "";
}

PassarelaUsuari::PassarelaUsuari(string sobrenomU, string nomU, string correuElectronicU, string contrasenyaU, string dataNaiexementU, string subscripcioU) {
	sobrenom = sobrenomU;
	nom = nomU;
	correuElectronic = correuElectronicU;
	contrasenya = contrasenyaU;
	dataNaixement = dataNaiexementU;
	modalitatsubscripcio = subscripcioU;
}

string PassarelaUsuari::obteSobrenom() {
	return sobrenom;
}

string PassarelaUsuari::obteNom() {
	return nom;
}

string PassarelaUsuari::obteCorreuElectronic() {
	return correuElectronic;
}

string PassarelaUsuari::obteContrasenya() {
	return contrasenya;
}

string PassarelaUsuari::obteDataNaixement() {
	return dataNaixement;
}

string PassarelaUsuari::obteSubscripcio() {
	return modalitatsubscripcio;
}

void PassarelaUsuari::insereix() const {
	ConnexioBD2& con = ConnexioBD2::getInstance();
	string query = "INSERT INTO usuari(sobrenom, nom, contrasenya, correu_electronic, data_naixement, subscripcio) VALUES('" 
		+ sobrenom + "', '" 
		+ nom + "', '" 
		+ contrasenya + "', '" 
		+ correuElectronic + "', STR_TO_DATE('" 
		+ dataNaixement + "', '%d/%m/%Y'), '" 
		+ modalitatsubscripcio + "')";
	con.exec(query);
}

void PassarelaUsuari::esborrar() const {
	ConnexioBD2& con = ConnexioBD2::getInstance();
	string query =  "DELETE FROM usuari WHERE sobrenom= '" + sobrenom +"'";
	con.exec(query);
}

void PassarelaUsuari::modifica() const {
	ConnexioBD2& con = ConnexioBD2::getInstance();
	string query = "UPDATE usuari SET nom = '" 
		+ nom + "', correu_electronic = '" 
		+ correuElectronic + "', contrasenya = '" 
		+ contrasenya + "', subscripcio = '" 
		+ modalitatsubscripcio + "', data_naixement = STR_TO_DATE('" 
		+ dataNaixement + "', '%d/%m/%Y') WHERE sobrenom = '" 
		+ sobrenom + "'";
	con.exec(query);
}
