#include "PassarelaVisualitzaSerie.h"
#include<sstream>

void PassarelaVisualitzaSerie::insereix() const {
	ConnexioBD2& con = ConnexioBD2::getInstance();
	std::ostringstream oss, ess;
	oss << numTemporada;
	ess << numCapitol;
	string query = "INSERT INTO visualitzacio_capitol (sobrenom_usuari, titol_serie, num_temporada, num_capitol, data, num_visualitzacions) "
		"VALUES ('" + sobrenom + "', '" + titolSerie + "', "
		+ oss.str() + ", " + ess.str() + ", NOW(), 1) "
		"ON DUPLICATE KEY UPDATE num_visualitzacions = num_visualitzacions + 1";
	con.exec(query);
}

void PassarelaVisualitzaSerie::modifica() const {
	ConnexioBD2& con = ConnexioBD2::getInstance();
	std::ostringstream oss, ess, oss2;
	oss << numTemporada;
	ess << numCapitol;
	oss2 << numVisualitzacions;
	string query = "UPDATE visualitzacio_capitol SET titol_serie = '"
		+ titolSerie + "', num_temporada = '"
		+ oss.str() + "', num_capitol = '"
		+ ess.str() + "', data = '"
		+ data + "', num_visualitzacions = '"
		+ oss2.str() + "',  WHERE sobrenom = '"
		+ sobrenom + "'";
	con.exec(query);
}

void PassarelaVisualitzaSerie::esborra() const {
	ConnexioBD2& con = ConnexioBD2::getInstance();
	string query = "DELETE FROM visualitzacio_capitol  WHERE sobrenom_usuari= '" + sobrenom + "'";
	con.exec(query);

}