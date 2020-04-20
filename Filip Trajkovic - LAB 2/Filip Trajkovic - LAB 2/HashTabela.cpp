#include "HashTabela.h"
#include "Termin.h"
#include <iostream>
#include <string>
#include <thread>

using namespace std;

HashTabela::HashTabela() {
	this->broj_el = 0;
	this->velicina = 10; //default velicina
	this->element = new Termin[this->velicina];
}
HashTabela::HashTabela(unsigned int velicina) {
	this->broj_el = 0;
	this->velicina = velicina;
	this->element = new Termin[velicina];
}
HashTabela::HashTabela(const HashTabela& ime) {
	this->velicina = ime.velicina;
	this->element = new Termin[ime.velicina];
	this->broj_el = ime.broj_el;
	for (unsigned int i = 0; i < ime.velicina; i++)
		this->element[i] = ime.element[i];
}
HashTabela::~HashTabela() {
	delete[] element;
}
void HashTabela::stampaj() {
	for (unsigned int i = 0; i < this->velicina; i++)
	{
		cout <<"Termin broj " << (i + 1)<<":" << endl;
		if (!element[i].isNull())
			element[i].informacije();
		else
			cout << "SLOBODNO MESTO!" << endl;
	}
}
void HashTabela::InfoKljuca(unsigned int kljuc) {
	element[kljuc].informacije();
}
bool HashTabela::prepraviSate(string time) {
	bool ret = true;
	int timeInt = Termin::VremeUInt(time);
	if (timeInt < 1000 || timeInt>1800)
		ret = false;
	return ret;
}
bool HashTabela::Postoji(Termin* ime) {
	for (int i = 0; i < this->broj_el; i++) {
		if (element[i] == *ime)
			return true;
		}
	return false;	
}
void HashTabela::Insert(Termin* ime) {
	if (Postoji(ime))
	{
		cout << "Element postoji u tabeli!" << endl;
		return;
	}
	if (this->velicina == this->broj_el)
	{
		cout << "Tabela je puna! Idite na drugi salter!" << endl;
		return;
	}
	else {
		if (!prepraviSate(ime->getTime()))
		{
			cout << "Salter je u ovo vreme zatvoren! Zakazite u vreme izmedju 10:00h i 18:00h" << endl;
			return;
		}
		else {
			unsigned int indeks = hash(ime->getDate(), ime->getTime());
			if (!(element[indeks].isNull())) 
				if (element[indeks].getDate() == ime->getDate() && element[indeks].getTime() == ime->getTime())
					indeks = kolizija(indeks);
			
			this->element[indeks] = *ime;
			this->broj_el++;
			cout << "Unet je element sa podacima: ";
			cout << element[indeks].getTime() << " ";
			cout << element[indeks].getDate() << " ";
			cout << element[indeks].getJMBG() << endl;
		}
	}
}
void HashTabela::InformacijeZaTermin(string date, string time) {
	cout << endl;
	cout<<"INFORMACIJE ZA UNETI TERMIN:"<<endl;
	if (!prepraviSate(time))
	{
		cout << "Je l vidis sta pise na salteru, radimo od 10::00h!" << endl;
		return;
	}
	if (this->broj_el == 0)
	{
		cout << "U fazi smo restruktuiranja preduzeca, nemamo nikakve podatke!" << endl;
		return;
		}
	unsigned int indeks = hash(date, time);
	int broj = 0;
	while (!(element[indeks].isNull()) && broj < broj_el) {
		if (element[indeks].getDate() == date && element[indeks].getTime() == time)
		{
			cout << "Ovo mozete da dobijete kod mene, ako hocete da se zalite idite kod sefa! " << endl;
			element[indeks].informacije();
			return;
		}
		else
		{
			broj++;
			indeks = kolizija(indeks);
		}
	}
	cout << "Je l vidis da pijem kafu, daj da vidim sta trazis to!" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	cout << "Nemam ja to kod mene, idi na drugi salter kod Cice!" << endl;
}
void HashTabela::brisi(){
	delete[] element;
}
unsigned int HashTabela::hash(string date, string time) {
	string pom = date + time;
	unsigned int hash = pom.length();
	unsigned int i = 0;
	for (i = 0; i < pom.length(); ++hash, ++i)
	{
		hash = ((hash << 5) ^ (hash >> 27)) ^ pom[i];
	}
	hash = hash % velicina;
	return hash;
}
unsigned int HashTabela::kolizija(unsigned int indeks) {
	int i = 1;
	do {
	indeks = (indeks + i * (i++)) % this->velicina;
	} 
	while (!(element[indeks].isNull()));
		
	return indeks;
}