#pragma once
class Sistema {
private:
	bool sessioUsuari;
	Sistema() {
		sessioUsuari = false;
	}

public:
	static Sistema& getInstance(){
		static Sistema instance;
		return instance;
	}

	bool essessioiniciada() {
		return sessioUsuari;
	}

	void sessioIniciada() {
		sessioUsuari = true;
	}

	void sessioTancada() {
		sessioUsuari = false;
	}
};

