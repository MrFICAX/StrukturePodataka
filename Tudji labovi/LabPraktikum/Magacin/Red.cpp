#pragma once
#include"Red.h"
Red::Red()
{
	niz = NULL;
	size = head = tail = brojTrenutnih = 0;
}
Red::Red(int n)
{
	size = n;
	head = tail = -1;
	brojTrenutnih = 0;
	niz = new int[size];
}
Red::~Red() { delete[] niz; }
int Red::getHead()
{
	if (head == -1)
	{
		throw"Nema elemenata u redu.";
	}
	return niz[head];
}
void Red::enqueue(int el)
{
	if (brojTrenutnih == size)
		throw "Nema raspolozivog prostora.";
	//DODAJEMO NA REP, CITAMO SA GLAVE!!!
	tail++;//dodajemo element pa se tejl uvecava
	if (tail == size)
		tail == 0;//ciklicno, ako smo stigli do kraja
	//vracamo se na pocetak
	niz[tail] = el;
	if (brojTrenutnih == 0)
	{
		head = tail;//ako je ovo prvi element u redu
		//onda su head i tail isti
	}
	brojTrenutnih++;
}
int Red::dequeue()
{
	if (brojTrenutnih == 0)
		throw "Nema elemenata.";
	int result = niz[head];//prvo uzmes element koji ti treba
	//pa onda pomeris indeks
	if (++head == size)
		head = 0;//ista prica kao gore
	brojTrenutnih--;
	if (brojTrenutnih == 0)//ako nema vise elemenata
		head = tail = -1;
	return result;
}
void Red::stampam()
{
	for (int i = head;i <= tail;i++)
		cout << niz[i] << " ";
	cout << endl;
}