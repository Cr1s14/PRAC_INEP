#include "CercadoraUsuari.h"

PassarelaUsuari CercadoraUsuari::cercaUsuari(string sobrenomU) {
	PassarelaUsuari u;
	ConnexioBD2& con = ConnexioBD2::getInstance();
	string sql = "SELECT * FROM usuari WHERE TRIM(sobrenom) = '" + sobrenomU + "'";
	sql::ResultSet* res = con.consulta(sql);
	// Si no troba cap fila, activa excepció
	if (!res->next()) {
		throw runtime_error("Usuari no existeix");
	}
	else {
		u.posaSobrenom(res->getString("sobrenom"));
		u.posaNom(res->getString("nom"));
		u.posaContrasenya(res->getString("contrasenya"));
		u.posaCorreuElectronic(res->getString("correu_electronic"));
		u.posaDataNaixement(res->getString("data_naixement"));
		u.posaSubscripcio(res->getString("subscripcio"));
		delete res;
	}
	return u;
}