#include "TxInfoVisualitzacions.h"

void TxInfoVisualitzacions::executar() {

	PetitFlix& petitflix = PetitFlix::getInstance();
	PassarelaUsuari u = petitflix.obteUsuari();
	string sobrenomU = u.obteSobrenom();

	CercadoraVisualitzaPel cercaP;
	CercadoraVisualitzaSerie cercaS;
	PassarelaVisualitzaPel p = cercaP.cercaVisualitzacions(sobrenomU);
	PassarelaVisualitzaSerie s = cercaS.cercaVisualitzacions(sobrenomU);

	nP = p.obteNumVisualitzacions();
	nS = p.obteNumVisualitzacions();
}

pair<int,int> TxInfoVisualitzacions::obteResultat() {
	pair<int, int> visualitzacions(nP, nS);
	return visualitzacions;
}
