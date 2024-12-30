#pragma once
#include <iostream>	
#include "PetitFlix.h"
#include "Sistema.h"
class TxTancaSessió {
public:
	TxTancaSessió() {
	
	}

	void executar(){
		PetitFlix& petitflix = PetitFlix::getInstance();
		petitflix.TancaSessio();
		Sistema& sys = Sistema::getInstance();
		sys.sessioTancada();
	}
};

