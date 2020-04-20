#pragma once
#include <iostream>
#include "Termin.h"
using namespace std;

class HashTabela {
protected:
	Termin* element;
	unsigned int velicina;
	unsigned broj_el;
private:
	void brisi();
	void setNull();
	unsigned int hash(string, string);
	unsigned int kolizija(unsigned int);
	bool prepraviSate(string);
	bool Postoji(Termin* ime);
	void InfoKljuca(unsigned int);	
public:
	HashTabela();
	HashTabela(const HashTabela&);
	HashTabela(unsigned int);
	~HashTabela();
	void InformacijeZaTermin(string, string);
	void Insert(Termin* ime);
	void stampaj();
};
