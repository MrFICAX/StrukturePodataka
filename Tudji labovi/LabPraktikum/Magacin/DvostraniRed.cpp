#include"DvostraniRed.h"

DvostraniRed::DvostraniRed()
{
	velicina = trenutniBroj = 0;
	head = tail = -1;
	niz = NULL;
}
DvostraniRed::DvostraniRed(int n)
{
	velicina = n;
	trenutniBroj = 0;
	niz = new int[velicina];
	head = tail = -1;
}
DvostraniRed::~DvostraniRed() { delete[] niz; }

int DvostraniRed::getHead() { return head; }
int DvostraniRed::getTail() { return tail; }
void DvostraniRed::enqueueHead(int a)
{
	if (trenutniBroj == velicina)
		throw "Puna je lista.";
	niz[++head] = a;
	if (trenutniBroj == 0)
	{
		head = tail = 0;
	}
	if (head-- == 0)
		head = velicina - 1;
	niz[head] = a;
	trenutniBroj++;
}