#include "CapaDePresentacio.h"
using namespace std;


void CapaDePresentacio::IniciSessio() {
	string sobrenomU, contrasenyaU;
	wcout << "** Inici sessió **" << endl;
	cout << "Sobrenom: ";
	cin >> sobrenomU;
	cout << "Contrasenya: ";
	cin >> contrasenyaU;
	TxIniciSessio tx(sobrenomU, contrasenyaU);
	try {
		tx.executar();
		wcout << "Sessió iniciada correctament!" << endl;
	}
	catch (const exception& e) {
		cout << "Error:" << e.what() << endl;
	}
	//Mostra missatge "Hi ha hagut un error amb el sobrenom o la contrasenya"
}

void CapaDePresentacio::TancaSessio() {
	char resposta;
	wcout << "Vols tancar la sessió? (S/N):";
	cin >> resposta;
	TxTancaSessió tx;
	if (resposta == 'S') {
		tx.executar();
		wcout << "Sessió tancada correctament" << endl;
	}	
}

void CapaDePresentacio::RegistrarUsuari() {
	string sobrenomU, nomU, correuU, contrasenyaU, dataNaixementU,subscripcioU;
	cout << "** Registrar usuari **" << endl;

	cout << "Nom complet: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, nomU);

	cout << "Sobrenom: ";
	getline(cin, sobrenomU);

	cout << "Contrasenya: ";
	getline(cin, contrasenyaU);

	wcout << "Correu electrònic: ";
	getline(cin, correuU);

	cout << "Data naixement (DD/MM/AAAA): ";
	getline(cin, dataNaixementU);

	wcout << "Modalitats de subscripció disponibles" << endl;
	cout << " > 1. Completa" << endl;
	wcout << " > 2. Cinèfil" << endl;
	cout << " > 3. Infantil" << endl;
	cout << "Escull modalitat: ";
	int opciosubscripcioU;
	cin >> opciosubscripcioU;

	switch (opciosubscripcioU) {
	case 1:
		subscripcioU = "Completa";
		break;
	case 2:
		subscripcioU = "Cinefil";
		break;
	case 3:
		subscripcioU = "Infantil";
		break;
	default:
		cout << "Modalitat no existeix" << endl;
		return;
	}

	TxRegistraUsuari tx(sobrenomU, nomU, correuU, contrasenyaU, dataNaixementU, subscripcioU);
	try {
		tx.executar();
			cout << "Usuari registrat correctament!" << endl;
	}
	catch (const exception& e) {
		cout << "Error:" << e.what() << endl;
	}
}

void CapaDePresentacio::ConsultaUsuari() {
	TxConsultaUsuari tx;
	TxInfoVisualitzacions tx2;
	try {
		tx.executar();
		tx2.executar();
		DTOUsuari infoUsuari = tx.obteResultat();
		pair<int, int> infoVisualitzacions = tx2.obteResultat();
		cout << "** Consulta Usuari **"<< endl;
		cout << "Nom complet: " << infoUsuari.obteNom() << endl;
		cout << "Sobrenom: " << infoUsuari.obteSobrenom() << endl;
		wcout << "Correu electrònic: ";
		cout << infoUsuari.obteCorreu() << endl;
		cout << "Data naixement (DD/MM/AAAA): " << infoUsuari.obteDataNaixement() << endl;	
		wcout << "Modalitat subscripció: ";
		cout << infoUsuari.obteSubscripcio() << endl;		
		cout << endl;
		cout << infoVisualitzacions.first;
		wcout << " pel·lícules visualitzades" << endl;
		cout << infoVisualitzacions.second;
		wcout << " capítols visualitzats" << endl;
	}
	catch (const exception& e) {
		cout << "Error:" << e.what() << endl;
	}
}

void CapaDePresentacio::ModificaUsuari() {
	string camp,nomU,contraU,correuU,neixU,modalitatU;
	nomU = contraU = correuU = neixU = modalitatU = "";
	cout << "** Modifica Usuari **" << endl;
	CtrlModificaUsuari ctrl;
	try {
		DTOUsuari infoU = ctrl.consultaUsuari();
		cout << "Nom complet: " << infoU.obteNom() << endl;
		cout << "Sobrenom: " << infoU.obteSobrenom() << endl;
		wcout << "Correu electrònic: ";
		cout << infoU.obteCorreu() << endl;
		cout << "Data naixement (DD/MM/AAAA): " << infoU.obteDataNaixement() << endl;
		wcout << "Modalitat subscripció: ";
		cout << infoU.obteSubscripcio() << endl;

		nomU = infoU.obteNom();
		correuU = infoU.obteCorreu();
		neixU = infoU.obteDataNaixement();
		modalitatU = infoU.obteSubscripcio();

		cout << endl;

		wcout << "Omplir la informació que es vol modificar ..." << endl;

		cout << "Nom complet: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, camp);
		if (!camp.empty()) {
			nomU = camp;
		}

		cout << "Contrasenya: ";
		getline(cin, camp);
		if (!camp.empty()) {
			contraU = camp;
		}

		wcout << "Correu electrònic: ";
		getline(cin, camp);
		if (!camp.empty()) {
			correuU = camp;
		}	

		cout << "Data naixement (DD/MM/AAAA): ";
		getline(cin, camp);	
		if (!camp.empty()) {
			neixU = camp;
		}	

		wcout << "Modalitat subscripció: ";
		getline(cin, camp);	
		if (!camp.empty()) {
			modalitatU = camp;
		}

		ctrl.modificaUsuari(nomU, contraU, correuU, neixU, modalitatU);
		cout << endl;

		infoU = ctrl.consultaUsuari();
		cout << "** Dades usuari modificades **" << endl;
		cout << "Nom complet: " << infoU.obteNom() << endl;
		cout << "Sobrenom: " << infoU.obteSobrenom() << endl;
		wcout << "Correu electrònic: ";
		cout << infoU.obteCorreu() << endl;
		cout << "Data naixement (DD/MM/AAAA): " << infoU.obteDataNaixement() << endl;
		wcout << "Modalitat subscripció: ";
		cout << infoU.obteSubscripcio() << endl;
	}
	catch (const exception& e) {
		cout << "Error:" << e.what() << endl;
	}

}

void CapaDePresentacio::EsborraUsuari() {
	cout << "** Esborra Usuari **" << endl;
	cout << "Per confirmar l'esborrat, s'ha d'entrar la contrasenya ..." << endl;
	string contraU;
	cout << "Contrasenya: ";
	cin >> contraU;
	TxEsborraUsuari tx(contraU);
	try {
		tx.executar();
		cout << "Usuari s'esborrat correctament" << endl;
	
	}
	catch (const exception& e) {
		cout << "Error:" << e.what() << endl;
	}
	// Mostra missatge "La contrasenya no és correcta. l'usuari no s'esborrat"
	// sinó, mostra missatge "Usuari no s'esborrat correctament"
}


void CapaDePresentacio::VisualitzaPeli() {
	wcout << "** Visualitzar Pel·lícula **"<< endl;
	wcout << "Nom pel·lícula: ";
	string peli;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, peli);
	cout << endl;

	VisualitzarPelicula tx(peli);
	try {
		tx.visualitzar();
	}
	catch (const exception& e) {
		cout << "Error:" << e.what() << endl;
	}
}

void CapaDePresentacio::VisualitzaSerie() {
	cout << "** Visualitzar Capitol **" << endl;
	string serie;
	cout << "Nom de la serie: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, serie);

	VisualitzarCapitol tx(serie);
	try {
		tx.visualitzar();
	}
	catch (const exception& e) {
		cout << "Error:" << e.what() << endl;
	}
}

void CapaDePresentacio::ConsultaVisualitzacions() {
	cout << "** Consulta visualitzacions **" << endl;
	cout << endl;
	wcout << "** Visualitzacions pel·lícules **" << endl;
	cout << "*********************************" << endl;
	TxConsultaVisualitzacions tx; 
	try {
		tx.executa();
		DTOVisPelicula p = tx.obtePeli();
		DTOVisSerie s = tx.obteSerie();
		DTOContingut c1 = tx.obteContingutPeli(), c2 = tx.obteContingutSerie();

		cout << p.obteData() << ": " << p.obteTitolPelicula() << "; " << c1.obteDescripcio() << "; " << c1.obteQualificacio() << "; "

			<< "nombre de visualitzacions: " << p.obteNumVisualitzacions() << endl;
		cout << endl;
		wcout << "** Visualitzacions Sèries **" << endl;
		cout << "*********************************" << endl;
		cout << s.obteData() << ": " << s.obteTitolSerie() << "; " << c2.obteQualificacio() << "; Temporada " << s.obteNumTemporada() << "; Capitol " << s.obteNumCapitol() << "; "
			<< "nombre de visualitzacions: " << s.obteNumVisualitzacions() << endl;
	
	}
	catch (const exception& e) {
		cout << "Error:" << e.what() << endl;
	}



}

void CapaDePresentacio::ProperesEstrenes() {
	ConsultaProperesEstrenes tx;
	try {
		tx.consulta();
	}
	catch (const exception& e) {
		cout << "Error:" << e.what() << endl;
	}
}

void CapaDePresentacio::UltimesNovetats() {
	ConsultaUltimesNovetats tx;
	try {
		tx.consulta();
	}
	catch (const exception& e) {
		cout << "Error:" << e.what() << endl;
	}
}

void CapaDePresentacio::PelisMesVistes() {
	wcout << "** Pel·lícules més visualitzades **" << endl;
	CtrlConsultarPelisMesVistes ctrl;
	Sistema& sys = Sistema::getInstance();
	bool acaba = false;
	try {
		ctrl.executar();
		int pos = 0;
		while (not acaba) {
			DTOContingutPel p = ctrl.obteContingutPelicula();
			if (p.obteTitol() == "") {
				acaba = true;
			}
			else {
				if (sys.essessioiniciada()) {
					cout << pos + 1 << ".- " << p.obteTitol() << "; " << p.obtequalificacio() << "; " << p.obteDuracio() << " min.; " << "Visualitzacions: " <<
						p.obteNumVisualitzacions() << "  [" << "VISTA: " << p.obteVista() << "]" << endl;
					++pos;
				}
				else if(!sys.essessioiniciada()) {
					cout << pos + 1 << ".- " << p.obteTitol() << "; " << p.obtequalificacio() << "; " << p.obteDuracio() << " min.; " << "Visualitzacions: " <<
						p.obteNumVisualitzacions() << endl;
					++pos;
				}	
			}
			if (pos >= 5) {
				acaba = true;
			}
		}
	}
	catch (const exception& e) {
		cout << "Error:" << e.what() << endl;
	}
}

void CapaDePresentacio::metePeli() {
	ConnexioBD2& con = ConnexioBD2::getInstance();

	string titol = "Frozen 3";
	string dataEstrena = "25/10/2025";
	string desc = "La reina helada vuelve a la gran pantalla";
	string qual = "TP";
	string tipus = "pelicula";
	int duracio = 160;

	std::ostringstream oss;
	oss << duracio;
	
	string queryedat = "INSERT IGNORE INTO qualificacio_edat (nom) VALUES ('"
		+ qual + "' )";
		
	string queryContingut = "INSERT INTO contingut (titol, descripcio, qualificacio, tipus) VALUES ('" 
		+ titol + "', '"
		+ desc + "', '"
		+ qual + "', '"
		+ tipus + "' )"; 

	string query = "INSERT INTO pelicula(titol,data_estrena,duracio) VALUES('"
		+ titol + "', STR_TO_DATE('"
		+ dataEstrena + "', '%d/%m/%Y'), '"
		+ oss.str() + "')";

	try {
		con.exec(queryedat);
		con.exec(queryContingut);
		con.exec(query);
		cout << "Peli inserida"<<endl;
	}
	catch (const exception& e) {
		cout << "Error:" << e.what() << endl;
	}
}

void CapaDePresentacio::meteSerie() {
	ConnexioBD2& con = ConnexioBD2::getInstance();

	string titol = "Alice in Borderland";
	string dataEstrena = "27/02/2026";
	string desc = "La vida dels jugadors continua en aquesta nova aventura";
	string qual = "16+";
	string tipus = "serie";
	int duracio = 120;

	int numT = 3;
	int numC = 1;
	string titolC = "Volvemos";

	std::ostringstream oss,oss2;
	oss << numT;
	oss2 << numC;

	string queryedat = "INSERT IGNORE INTO qualificacio_edat (nom) VALUES ('"
		+ qual + "' )";


	string queryContingut = "INSERT IGNORE INTO contingut (titol, descripcio, qualificacio, tipus) VALUES ('"
		+ titol + "', '"
		+ desc + "', '"
		+ qual + "', '"
		+ tipus + "' )";

	string query = "INSERT IGNORE INTO serie(titol,data_estrena) VALUES('"
		+ titol + "', STR_TO_DATE('"
		+ dataEstrena + "', '%d/%m/%Y') )";

	string queryCap = "INSERT IGNORE INTO capitol(titol_serie,numero_temporada,numero,titol,data_estrena,qualificacio) VALUES ('"
		+ titol + "', '"
		+ oss.str() + "', '"
		+ oss2.str() + "', '"
		+ titolC + "', STR_TO_DATE('" 
		+ dataEstrena + "','%d/%m/%Y'), '"
		+ qual + "' )";
	string queryTem = "INSERT IGNORE INTO temporada(titol_serie, numero) VALUES ('"
		+ titol + "', '"
		+ oss.str() + "')";


	try {
		con.exec(queryedat);
		con.exec(queryContingut);
		con.exec(query);
		con.exec(queryCap);
		con.exec(queryTem);
		cout << "Capitol inserit" << endl;
	}
	catch (const exception& e) {
		cout << "Error:" << e.what() << endl;
	}
}
