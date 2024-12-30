#include "CercadoraVisualitzaPel.h"

PassarelaVisualitzaPel CercadoraVisualitzaPel::cercaVisualitzacions(string sobrenom) {
	PassarelaVisualitzaPel p;
	string query = "SELECT SUM(num_visualitzacions) AS num_visualitzacions FROM visualitzacio_pelicula WHERE sobrenom_usuari = '" + sobrenom + "'";
	ConnexioBD2& con = ConnexioBD2::getInstance();
	sql::ResultSet* res = con.consulta(query);
	if (res->next()) {
		int visualitzacions = res->getInt("num_visualitzacions");
		p.posaNumVisualitzacions(visualitzacions);
		delete res;
	} 
	return p;
}

PassarelaVisualitzaPel CercadoraVisualitzaPel::cercaVisPel(string sobrenom) {
	PassarelaVisualitzaPel p;
	string query = "SELECT * FROM visualitzacio_pelicula WHERE sobrenom_usuari = '" + sobrenom + "'";
	ConnexioBD2& con = ConnexioBD2::getInstance();
	sql::ResultSet* res = con.consulta(query);
	if (res->next()) {
		p.posaSobrenom(res->getString("sobrenom_usuari"));
		p.posaTitolPelicula(res->getString("titol_pelicula"));
		p.posaData(res->getString("data"));
		p.posaNumVisualitzacions(res->getInt("num_visualitzacions"));
		delete res;
	}
	return p;
}