#pragma once
#include <iostream>
using namespace std;
class prueba {
private:
	string t;
public:
	prueba() {
	}

	prueba(string l) {
		t = l;
	}

	void executar() {
		cout << t;
	}
};

