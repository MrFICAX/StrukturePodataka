#include "Cvor.h"
#include <iostream>
using namespace std;

Cvor::Cvor() {
	this->kljuc = 0;
	this->levi = NULL;
	this->desni = NULL;
}
Cvor::Cvor(int el) {
	this->kljuc = el;
	this->levi = NULL;
	this->desni = NULL;
}
Cvor::Cvor(int el, Cvor* Levitmp, Cvor* Desnitmp) {
	this->kljuc = el;
	this->levi = Levitmp;
	this->desni = Desnitmp;
}
bool Cvor::jeManji(int el) {
	if (kljuc < el)
		return true;
	else
		return false;
}
bool Cvor::jeVeci(int el) {
	if (kljuc > el)
		return true;
	else
	return false;
}
bool Cvor::jeJednak(int el) {
	if (kljuc == el)
		return true;
	else
		return false;
}
void Cvor::postaviKljuc(int el) {
	this->kljuc = el;
}
int Cvor::vratiKljuc() {
	return this->kljuc;
}
void Cvor::stampajKljuc() {
	cout <<"Vrednost kljuca je: "<< kljuc << endl;
}
Cvor* Cvor::getLevi()
{
    return levi;
}

void Cvor::setLevi(Cvor* levi)
{
    this->levi = levi;
}

Cvor* Cvor::getDesni()
{
    return desni;
}

void Cvor::setDesni(Cvor* desni)
{
    this->desni = desni;
}

