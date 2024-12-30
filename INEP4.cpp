#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include "ConnexioBD2.h"
#include "CapaDePresentacio.h"
#include "PassarelaUsuari.h"
#include <locale>

using namespace std;

void mostrarMenuPrincipal() {
    cout << "*********************"<< endl;
    cout << "    Menú principal\n";
    cout << "*********************"<< endl;
    cout << "1. Iniciar sessió\n";
    cout << "2. Registrar usuari\n";
    cout << "3. Consultes\n";
    cout << "4. Sortir\n";
    cout << "Escriu opció: ";
}

void mostrarMenuUsuariIniciat() {
    cout << "*********************" << endl;
    cout << "    Menú principal\n";
    cout << "*********************" << endl;
    cout << "1. Gestió usuaris\n";
    cout << "2. Visualitzar\n";
    cout << "3. Consultes\n";
    cout << "4. Tancar sessió\n";
    cout << "5. Sortir\n";
    cout << "Escriu opció: ";

}

void mostrarMenuVisualitzar() {
    cout << "---------------------------" << endl;
    cout << "         Visualitzar\n";
    cout << "---------------------------" << endl;
    cout << "1. Visualitzar pel·lícula\n";
    cout << "2. Visualitzar capítol\n";
    cout << "3. Consulta visualitzacions\n";
    cout << "4. Tornar\n";
	cout << "Escriu opció: ";
}

void processarVisualitzar() {
    int opcio = 0;
	bool primeraVegada = true;
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    do {
        if (not primeraVegada) {
            mostrarMenuVisualitzar();
        }
        cin >> opcio;
        cout << endl;

        if (opcio == 1) {
            presentacio.VisualitzaPeli();
            cout << endl;
        
        }
        else if (opcio == 2) {
            presentacio.VisualitzaSerie();
            cout << endl;
        
        }
        else if (opcio == 3) {
            presentacio.ConsultaVisualitzacions();
        
        }
		primeraVegada = false;
    } while (opcio != 4);
}

void mostrarMenuGestioUsuari() {
    cout << "---------------------------" << endl;
    cout << "      Gestió Usuari\n";
    cout << "---------------------------" << endl;
    cout << "1. Consulta usuari\n";
    cout << "2. Modifica usuari\n";
    cout << "3. Esborra usuari\n";
    cout << "4. Tornar\n";
    cout << "Escriu opció: ";
}

void processarGestioUsuari() {
    int opcio = 0;
	CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    bool primeraVegada = true;

    do {
        if (not primeraVegada) {
            mostrarMenuGestioUsuari();
        }
        cin >> opcio;
        cout << endl;
        if (opcio == 1) {
			presentacio.ConsultaUsuari();
            cout << endl;

        }
        else if (opcio == 2) {
			presentacio.ModificaUsuari();
            cout << endl;

        }
        else if (opcio == 3) {
			presentacio.EsborraUsuari();
            cout << endl;
            break; 

        }
		primeraVegada = false;
    } while (opcio != 4);
}

void mostrarMenuConsultes() {
    cout << "---------------------------" << endl;
    cout << "          Consultes\n";
    cout << "---------------------------" << endl;
    cout << "1. Properes estrenes\n";
    cout << "2. Últimes novetats\n";
    cout << "3. Pel·lícules més vistes\n";
    cout << "4. Tornar\n";
    cout << "Escriu opció: ";
}

void processarConsultes() {
    int opcio = 0;
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
	bool primeraVegada = true;
    do {
        if (not primeraVegada) {
			mostrarMenuConsultes();

        }
        cin >> opcio;
        cout << endl;
        if (opcio == 1) {
            presentacio.ProperesEstrenes();
            cout << endl;
        }
        else if (opcio == 2) {
            presentacio.UltimesNovetats();
            cout << endl;
        }
        else if (opcio == 3) {
            presentacio.PelisMesVistes();
            cout << endl;
        }
		primeraVegada = false;
    } while (opcio != 4);
}

int main() {
	locale::global(locale("es_ES.UTF-8"));

    int opcio1, opcio2;
	opcio1 = opcio2 = 0;

	CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    Sistema& sys = Sistema::getInstance();

    do {
        if (not sys.essessioiniciada()) {
            mostrarMenuPrincipal();
            cin >> opcio1;
            cout << endl;

            if (opcio1 == 1) {
                presentacio.IniciSessio();
                cout << endl;
            }
            else if (opcio1 == 2) {
                presentacio.RegistrarUsuari();
                cout << endl;
            }
            else if (opcio1 == 3) {
                mostrarMenuConsultes();
           
                processarConsultes();
            }
            else if (opcio1 == 4) {
                cout << "Sortint de l'aplicació...\n";
            }
        }
        else {
			mostrarMenuUsuariIniciat();
			cin >> opcio2;
            cout << endl;

			if (opcio2 == 1) {
				mostrarMenuGestioUsuari();
               
                processarGestioUsuari();
			}
			else if (opcio2 == 2) {
				mostrarMenuVisualitzar();
                
                processarVisualitzar();
			}
			else if (opcio2 == 3) {
				mostrarMenuConsultes();
                
                processarConsultes();
			}
			else if (opcio2 == 4) {
				presentacio.TancaSessio();
                cout << endl;
			}
			else if (opcio2 == 5) {
				cout << "Sortint de l'aplicació...\n";
			}
        }
      
    } while (opcio1 != 4 && opcio2 != 5);
}