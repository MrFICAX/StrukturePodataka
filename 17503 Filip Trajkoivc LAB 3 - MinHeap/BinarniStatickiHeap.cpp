#include "BinarniStatickiHeap.h"
#include <iostream>

using namespace std;

BinarniStatickiHeap::BinarniStatickiHeap() {
	this->velicina = 0;
	this->brojEl = 0;
	this->niz = NULL;
}
BinarniStatickiHeap::BinarniStatickiHeap(int vel) {
	this->velicina = vel;
	this->brojEl = 0;
	this->niz = new int[this->velicina+1];
	for (int i = 0; i < this->velicina+1; i++)
		this->niz[i] = -1;
}
BinarniStatickiHeap::BinarniStatickiHeap(BinarniStatickiHeap& tmp) {
	if (this != &tmp) {
		this->velicina = tmp.velicina;
		this->brojEl = tmp.brojEl;
		niz = new int[velicina];
		for (int i = 0; i < tmp.velicina; i++)
			this->niz[i] = tmp.niz[i];
	}
}
BinarniStatickiHeap::~BinarniStatickiHeap() {
	this->velicina = 0;
	this->brojEl = 0;
	if(this->niz != NULL)
	delete[] niz;
}
void BinarniStatickiHeap::dodaj(int el) {

	if (brojEl == velicina )
	{
		cout << "Heap je pun!" << endl;
		return;
	}
	else
	{
		brojEl++;
		int i = brojEl;
		while (i>1 && niz[i/2]>el)
		{
			niz[i] = niz[i / 2];
			i = i / 2;
		}
		niz[i] = el;
	}
}
void BinarniStatickiHeap::brisiKoren() {
	if (brojEl == 0)
	{
		cout << "Heap je prazan!" << endl;
		return;
	}
	else
	{
		int result = niz[1];
		int  last = niz[brojEl];
		niz[brojEl] = -1;
		brojEl--;
		int i = 1;
		while (2 * i < brojEl + 1)
		{
			int child = 2 * i;
			if (child + 1 < brojEl + 1 && niz[child + 1] < niz[child])
				child += 1;
			if (last <= niz[child]) break;
			niz[i] = niz[child];
			i = child;
		}
		niz[i] = last;

	}
}
BinarniStatickiHeap* BinarniStatickiHeap::KopijaUOgledalu()
{
	cout << "----------------" << endl;
	cout << "Kopija u ogledalu: " << endl;
	if (jePotpuno()) {
		BinarniStatickiHeap* pom = new BinarniStatickiHeap(*this);
		int indeks = 2;
		int i;
		int j;
		for (indeks; indeks < velicina; indeks *= 2)
		{
			i = indeks;
			j = indeks * 2 - 1;
			for (i; i < indeks * 2; i++)
			{
				pom->niz[j] = this->niz[i];
				j--;
			}
		}
		return pom;
	}
	else
	{
		cout << "MinHeap nije potpuno stablo!" << endl;
		return nullptr;
	}
}
void BinarniStatickiHeap::stampajPoSirini() {
	if (this != NULL) {
		if (brojEl != 0) {
			cout << "Elementi niza su: " << endl;
			for (int i = 1; i <= velicina; i++)
				cout << niz[i] << endl;
			cout << "------------------" << endl;
		}
		else
		{
			cout << "Heap je prazan!";
		}
	}
	else
	{
		return;
	}
}
void BinarniStatickiHeap::stampajPoDubini(int el) {
	if (brojEl == 0) {
		cout << "Heap je prazan!" << endl;
		return;
	}
	else
	{
		int indeks = 1;
		while (indeks < brojEl + 1 && niz[indeks] != el)
			indeks++;
		int* niz = new int[velicina / 2];
		int pom = indeks;
		int i = 0;
		while (pom != 0) {
			niz[i] = this->niz[pom];
			pom /= 2;
			i++;
		}
		cout << "Niz po dubini do elementa: " <<el<< endl;
		i--;
		for (i; i >= 0 ; i--)
			cout << niz[i] << endl;
	}
}

bool BinarniStatickiHeap::jePotpuno()
{
	int indeks = 2;
	int i;
	for (indeks; indeks < velicina; indeks *= 2)
	{
		i = indeks;
		for (i; i < indeks * 2; i++)
		{
			if (niz[i] == -1)
				return false;
		}
	}
	return true;
}


