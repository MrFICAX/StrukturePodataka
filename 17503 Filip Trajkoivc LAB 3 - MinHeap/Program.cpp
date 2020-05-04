#include "BinarniStatickiHeap.h"
#include <iostream>
using namespace std;

void main() {
	//Dodato je 15 elemenata i formirano je potpuno stablo te stoga ce kopija u ogledalu odraditi svoj posao 
	BinarniStatickiHeap* instanca = new BinarniStatickiHeap(15);
	instanca->dodaj(5);
	instanca->dodaj(4);
	instanca->dodaj(10);
	instanca->dodaj(3);
	instanca->dodaj(2);
	instanca->dodaj(25);
	instanca->dodaj(21);
	instanca->dodaj(113);
	instanca->dodaj(14);
	instanca->dodaj(15);
	instanca->dodaj(35);
	instanca->dodaj(31);
	instanca->dodaj(123);
	instanca->dodaj(11);
	instanca->dodaj(18);
//	instanca->brisiKoren();  //Ukoliko ovde izvrsite funkciju brisanja korena, imacemo 14 elemenata i nece se izvrsiti funkcija kopije u ogledalu
	instanca->stampajPoSirini();
	instanca->stampajPoDubini(113);

	BinarniStatickiHeap* pom;
	pom = instanca->KopijaUOgledalu();
	pom->stampajPoSirini();
}