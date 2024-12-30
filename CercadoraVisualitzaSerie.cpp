#include "CercadoraVisualitzaSerie.h"

PassarelaVisualitzaSerie CercadoraVisualitzaSerie::cercaVisualitzacions(string sobrenom) {
	PassarelaVisualitzaSerie s;
	string query = "SELECT SUM(num_visualitzacions) AS num_visualitzacions FROM visualitzacio_capitol WHERE sobrenom_usuari = '" + sobrenom + "'";
	ConnexioBD2& con = ConnexioBD2::getInstance();
	sql::ResultSet* res = con.consulta(query);
	if (res->next()) {
		int visualitzacions = res->getInt("num_visualitzacions");
		s.posaNumVisualitzacions(visualitzacions);
		delete res;
	}
	return s;
}

PassarelaVisualitzaSerie CercadoraVisualitzaSerie::cercaVisSerie(string sobrenom) {
	PassarelaVisualitzaSerie s;
	string query  = "SELECT * FROM visualitzacio_capitol WHERE sobrenom_usuari = '" + sobrenom + "'";
	ConnexioBD2& con = ConnexioBD2::getInstance();
	sql::ResultSet* res = con.consulta(query);
	if (res->next()) {
		s.posaSobrenom(res->getString("sobrenom_usuari"));
		s.posaTitolSerie(res->getString("titol_serie"));
		s.posaNumTemporada(res->getInt("num_temporada"));
		s.posaNumCapitol(res->getInt("num_capitol"));
		s.posaData(res->getString("data"));
		s.posaNumVisualitzacions(res->getInt("num_visualitzacions"));
		delete res;
	}
	return s;
}
