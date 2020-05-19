#pragma once
#include "LinkedNode.h"
#include <queue>
#include <math.h> 

using namespace std;

template <class T>
class GrafKaoLista {
protected:
	LinkedNode<T>* start;
	long nodeNum;
public:
	inline GrafKaoLista() {
		start = NULL;
		nodeNum = 0;
	}
	~GrafKaoLista();
	LinkedNode<T>* findNode(T pod);
	Edge<T>* findEdge(T a, T b);
	void insertNode(T pod);
	void insertEdge(T a, T b);
	long breadthTrav(T a);
	void print();

	void brNeusmerenih();
	bool minGraf(T a, T b);
};

template<class T>
GrafKaoLista<T>::~GrafKaoLista() {
	delete start;
}

template<class T>
LinkedNode<T>* GrafKaoLista<T>::findNode(T pod) {
	LinkedNode<T>* ptr = start;
	while (ptr != NULL && ptr->node != pod)
	{
		ptr = ptr->next;
	}
	return ptr;
}

template<class T>
Edge<T>* GrafKaoLista<T>::findEdge(T a, T b) {
	LinkedNode<T>* pa = findNode(a);
	LinkedNode<T>* pb = findNode(b);
	if (pa == NULL && pb == NULL) return NULL;
	Edge<T>* ptr = pa->adj;
	while (ptr != NULL && ptr->dest != pb)
	{
		ptr = ptr->link;
	}
	return ptr;
}
template<class T>
void GrafKaoLista<T>::insertNode(T pod) {
	LinkedNode<T>* newNode = new LinkedNode<T>(pod, NULL, start, 0);
	start = newNode;
	nodeNum++;
}
template<class T>
void GrafKaoLista<T>::insertEdge(T a, T b) {
	LinkedNode<T>* pa = findNode(a);
	LinkedNode<T>* pb = findNode(b);
	Edge<T>* pom = new Edge<T>(pb, pa->adj); //usmereni graf je tako da se dodaje grana samo listi jednog cvora
	pa->adj = pom;
}
template <class T>
long GrafKaoLista<T>::breadthTrav(T a) {
	cout << "Obilazak grafa po susedima od : " << a << endl;
	long retVal = 0;
	LinkedNode<T>* ptr = start;
	queue<LinkedNode<T>*> que;
	while (ptr != NULL)
	{
		ptr->status = 1;
		ptr = ptr->next;
	}
	ptr = findNode(a);
	if (ptr == NULL)
	{
		return 0;
	}
	que.push(ptr);
	ptr->status = 2;
	while (!que.empty()) {
		ptr = que.front();

		ptr->status = 3;
		ptr->Visit();
		retVal++;
		Edge<T>* pot = ptr->adj;
		que.pop();
		while (pot != NULL)
		{
			if (pot->dest->status == 1) {
				pot->dest->status = 2;
				que.push(pot->dest);
			}
			pot = pot->link;
		}
	}
	return retVal;
}
template<class T>
void GrafKaoLista<T>::print() {
	LinkedNode<T>* ptr = start;
	while (ptr != NULL)
	{
		cout << ptr->node << "->";
		Edge<T>* pa = ptr->adj;
		while (pa != NULL)
		{
			cout << pa->dest->node << "|";
			pa = pa->link;

		}
		cout << "\r\n";
		ptr = ptr->next;
	}
}
template<class T>
void GrafKaoLista<T>::brNeusmerenih() // funkcija pronalazi sve 
{
	LinkedNode<T>* pom = start; //ovaj pokazivac ide kroz listu cvorova
	Edge<T>* pom2; //ovaj pokazivac ide kroz listu suseda datog cvora iz pom
	Edge<T>* pom3; // ovaj pokazivac ide kroz listu suseda, susednog cvora datog cvora iz pom 
	unsigned int tmpBr = 0;
	 while(pom != nullptr)
	{
		pom2 = pom->adj;
		while (pom2 != NULL)
		{
			pom3 = pom2->dest->adj;
			while (pom3 != NULL && pom3->dest != pom)
			{
				pom3 = pom3->link;
			}
			if (pom3 != NULL && pom3->dest == pom)
				tmpBr++;
			pom2 = pom2->link;
		}
		pom = pom->next;
	}
	 cout << "Broj neusmerenih potega u grafu je: " << tmpBr / 2 << endl;
}

template<class T>
 bool GrafKaoLista<T>::minGraf(T a, T b)
{
	 cout << "Obilazak minimalnog puta od " << a << " do " << b << ": " << endl;
	LinkedNode<T>* ptr = start;
	queue<LinkedNode<T>*> que;
	while (ptr != NULL)
	{
		ptr->status = 1;
		ptr->duzinaPuta = INT_MAX;
		ptr = ptr->next;
	}
	ptr = findNode(a);
	if (ptr == NULL)
	{
		cout << "Nije pronadjen pocetni cvor!" << endl;
		return false;
	}
	if (ptr->adj == NULL)
	{
		cout << "Pocetni cvor nema sledbenika!" << endl;
		return false;
	}
		Edge<T>* tmp = ptr->adj;
		while (tmp != NULL) //provera da li postoji loop slucaj, namerno je ovde postavljen radi ustede vremena 
		{
			if (tmp->dest->node == a)
			{
				cout << ptr->node << " -> " << ptr->node << endl;
				return true;
			}
			tmp = tmp->link;
		}
	que.push(ptr);
	ptr->status = 2;
	ptr->duzinaPuta = 0;
	while (!que.empty())
	{
		ptr = que.front();
		ptr->status = 3;
		Edge<T>* pot = ptr->adj;
		que.pop();
		while (pot != NULL)//  && ptr->node != b)
		{
			if (pot->dest->status == 1) 
			{
				pot->dest->status = 2;
				if (ptr->duzinaPuta + 1 < pot->dest->duzinaPuta)
				{
					pot->dest->duzinaPuta = ptr->duzinaPuta + 1;
					pot->dest->prev = ptr;
				}
				que.push(pot->dest);
			}
			pot = pot->link;
		}
	}
	int* niz = new int[nodeNum]; //niz je samo struktura radi bolje preglednosti prikaza puta, nije neophodno; nefunkcionalno je i zauzima veliki prostor vremena za veliki broj cvorova
	int i = 0;
	LinkedNode<T>* poslednji = start;
	if (a != b) {
		while (poslednji != NULL && poslednji->node != b)
			poslednji = poslednji->next;
		if (poslednji == NULL)
		{
			cout << "--------------------------------------" << endl;
			cout << "Nije pronadjen prosledjeni krajnji cvor!" << endl;
			cout << "--------------------------------------" << endl;
			return false;
		}
		while (poslednji != NULL && poslednji->node != a)
		{
			niz[i] = poslednji->node;
			i++;
			poslednji = poslednji->prev;
		}
		if (poslednji == NULL)
		{
			cout << "--------------------------------------" << endl;
			cout << "Ne postoji put izmedju ova dva cvora!" << endl;
			cout << "--------------------------------------" << endl;
			return false;
		}
		niz[i] = poslednji->node;
		while (i > 0)
		{
			cout << niz[i] << " -> ";
			i--;
		}
		cout << niz[i] << endl;
		delete[] niz;
		return true;
	}
	else
	{
		poslednji = start;
		while ((poslednji != NULL && poslednji->prev != NULL && poslednji->adj == NULL) || poslednji->prev == NULL )
			poslednji = poslednji->next;
		if (poslednji == NULL)
		{
			cout << "--------------------------------------" << endl;
			cout << "Nije pronadjen prosledjeni krajnji cvor!" << endl;
			cout << "--------------------------------------" << endl;
			return false;
		}
		while (poslednji != NULL && poslednji->node != a)
		{
			niz[i] = poslednji->node;
			i++;
			poslednji = poslednji->prev;
		}
		if (poslednji == NULL)
		{
			cout << "--------------------------------------" << endl;
			cout << "Ne postoji put izmedju ova dva cvora!" << endl;
			cout << "--------------------------------------" << endl;
			return false;
		}
		niz[i] = poslednji->node;
		while (i > 0)
		{
			cout << niz[i] << " -> ";
			i--;
		}
		cout << niz[i] << endl;
		delete[] niz;
		return true;
	}
}