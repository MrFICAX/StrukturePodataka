#include"Quick.h"
#include<iostream>
using namespace std;
Quick::Quick() {
	this->brElem = 0;
	niz = NULL;
}
Quick::Quick(int n) {
	this->brElem = n;
	this->niz = new int[brElem];

}
Quick::~Quick() { delete[] niz; }
void Quick::quickSort(int *niz, int brElemPrim)
{
	if (this->brElem < 2)
		return;//ako niz ima 1 element, onda nema sta

	quickSort(niz, 0, this->brElem - 1);
}
void Quick::quickSort(int *niz, int first, int last)
{
	int lower = first + 1;
	int upper = last;
	int bound = niz[first];//bound je pivot
	while (lower <= upper)
	{
		//sa desne strane trazimo manje, jer ih hocemo na levoj strani,
		//a sleva vece jer ih hocemo na desnoj strani
		while (niz[lower] < bound && lower < last)
			//teras sve dok je pivot veci od tekuceg ili ne stignes do kraja
			lower++;
		//GLEDAJ OVAMO:
		//JAKO JE PROSTO TI OVOM PETLJOM OSTAVLJAS SVE MANJE OD PIVOTA SA LEVE STRANE
		//A OVOM DRUGOM SVE VECE OSTAVLJAS DESNO
		//URADI PRIMER SA OVIM BROJEVIMA I BICE TI JASNO:
		//9 7 5 11 12 2 14 3 10 6
		while (bound<niz[upper] && upper>first)
			//a ovde obrnutno dok je pivot manji od tekuceg, a poso si otpozadi i treba 
			//da stignes do prvog
			upper--;
		if (lower < upper)//menjas mesta ako je indeks lower manji od indeksa upper
			swap(lower++, upper--);
		else
			lower++;
	}

	swap(first, upper);
	if (first < upper - 1)
		//Ovim uslovom utvrdjuemo da li u podnizu ima vise od 1 elementa.
		//Ako je first=upper-1 to znaci da je tu tacno 1 element, 
		//A ako je gorenavedeni uslov ispunjen, imas vise elemenata.
		//Nacrtaj primer i idi korak po korak.
		//Moj primer: 3 6 2 4 7 - pocetni niz
		//Posle while-a: 3 2 6 4 7
		//kad si doso do ovde niz posle swap fje izgleda ovako: 2 3 6 4 7
	{
		quickSort(niz, first, upper - 1);
	}
	if (upper + 1 < last)
	{
		quickSort(niz, upper + 1, last);
	}
}
istream&  operator >> (istream& in, Quick& q) {
	cout << "Unesite elemente niza: " << endl;
	for (int i = 0;i < q.brElem;i++)
	{
		in >> q.niz[i];
	}
	return in;
}
ostream& operator<<(ostream& out, const Quick& q)
{
	for (int i = 0;i < q.brElem;i++)
		out << q.niz[i] << " ";
	out << endl;
	return out;
}
void Quick::swap(int first, int upper)
{
	int pom = niz[first];
	this->niz[first] = this->niz[upper];
	niz[upper] = pom;
}