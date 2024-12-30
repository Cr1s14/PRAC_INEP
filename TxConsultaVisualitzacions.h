#pragma once
#include <iostream>
#include "PassarelaVisualitzaPel.h"
#include "PassarelaVisualitzaSerie.h"
#include "PassarelaContingut.h"
#include "CercadoraVisualitzaPel.h"
#include "CercadoraVisualitzaSerie.h"
#include "CercadoraContingut.h"
#include "PetitFlix.h"
#include "DTOVisSerie.h"
#include "DTOPelicula.h"
#include "DTOContingut.h"

using namespace std;

class TxConsultaVisualitzacions {
	private:
		PassarelaVisualitzaPel peli;
		PassarelaContingut con_peli;

		PassarelaVisualitzaSerie serie;
		PassarelaContingut con_serie;

	public:
		TxConsultaVisualitzacions() {
		
		}

		void executa() {
			CercadoraVisualitzaPel cerca1;
			CercadoraVisualitzaSerie cerca2;

			PetitFlix& petitflix = PetitFlix::getInstance();
			PassarelaUsuari pU = petitflix.obteUsuari();
			std::string sobrenomUsuari = pU.obteSobrenom();

			peli = cerca1.cercaVisPel(sobrenomUsuari);
			serie = cerca2.cercaVisSerie(sobrenomUsuari);

			CercadoraContingut cP, cS;
			con_peli = cP.cercaContingut(peli.obteTitolPelicula());
			con_serie = cS.cercaContingut(serie.obteTitolSerie());
		}

		DTOVisPelicula obtePeli() {
			DTOVisPelicula p(peli.obteSobrenom(), peli.obteTitolPelicula(), peli.obteData(), peli.obteNumVisualitzacions());
			return p;
		}

		DTOVisSerie obteSerie() {
			DTOVisSerie s(serie.obteSobrenom(), serie.obteTitolSerie(), serie.obteNumVisualitzacions(), serie.obteNumTemporada(), serie.obteNumCapitol(), serie.obteData());
			return s;
		}

		DTOContingut obteContingutPeli() {
			DTOContingut c1(con_peli.obteTitol(), con_peli.obteDescripcio(), con_peli.obteQualificacio(), con_peli.obteTipus());
			return c1;
		}

		DTOContingut obteContingutSerie() {
			DTOContingut c2(con_serie.obteTitol(), con_serie.obteDescripcio(), con_serie.obteQualificacio(), con_serie.obteTipus());
			return c2;
		}
};

