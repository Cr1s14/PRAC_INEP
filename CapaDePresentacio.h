#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include "ConnexioBD2.h"
#include "DTOUsuari.h"
#include "TxRegistraUsuari.h"
#include "TxConsultaUsuari.h"
#include "TxIniciSessio.h"
#include "TxTancaSessió.h"
#include "TxInfoVisualitzacions.h"
#include "TxEsborraUsuari.h"
#include "CtrlModificaUsuari.h"
#include "Sistema.h"
#include "TxVisualitzaPelicula.h"
#include "TxVisualitzaSerie.h"
#include "TxConsultaVisualitzacions.h"
#include "CtrlConsultarPelisMesVistes.h"
#include "DTOPelicula.h"
#include <locale>
#include <sstream>
#include "DTOContingut.h"
#include "DTOPelicula.h"
#include "DTOVisSerie.h"
#include "TxConsultaProperesEstrenes.h"
#include "TxConsultaUltimesNovetats.h"
#include "PassarelaContingutPel.h"
class CapaDePresentacio {
	private:
		CapaDePresentacio() { 
		}

	public:
		static CapaDePresentacio& getInstance() {
			static CapaDePresentacio instance;
			return instance;
		}

		void IniciSessio();
		void TancaSessio();
		void RegistrarUsuari();
		void ConsultaUsuari();
		void ModificaUsuari();
		void EsborraUsuari();

		void VisualitzaPeli();
		void VisualitzaSerie();
		void ConsultaVisualitzacions();

		void ProperesEstrenes();
		void UltimesNovetats();
		void PelisMesVistes();

		void metePeli();
		void meteSerie();
};

