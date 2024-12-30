#include "PassarelaVisualitzaPel.h"
#include <sstream>

void PassarelaVisualitzaPel::insereix() const {
	ConnexioBD2& con = ConnexioBD2::getInstance();
	string query = "INSERT INTO visualitzacio_pelicula (sobrenom_usuari, titol_pelicula, data, num_visualitzacions) "
		"VALUES ('" + sobrenom + "', '" + titolPelicula + "', NOW(), 1) "
		"ON DUPLICATE KEY UPDATE num_visualitzacions = num_visualitzacions + 1";
	con.exec(query);
}

void PassarelaVisualitzaPel::modifica() const {
	ConnexioBD2& con = ConnexioBD2::getInstance();
	std::ostringstream oss;
	oss << numVisualitzacions;
	string query = "UPDATE visualitzacio_pelicula SET titol_pelicula = '"
		+ titolPelicula + "', data = '"
		+ data + "', num_visualitzacions = '"
		+ oss.str() + "' WHERE sobrenom_usuari = '"
		+ sobrenom + "'";
	con.exec(query);
}

void PassarelaVisualitzaPel::esborra() const {
	ConnexioBD2& con = ConnexioBD2::getInstance();
	string query = "DELETE FROM visualitzacio_pelicula WHERE sobrenom_usuari= '" + sobrenom + "'";
	con.exec(query);

}
