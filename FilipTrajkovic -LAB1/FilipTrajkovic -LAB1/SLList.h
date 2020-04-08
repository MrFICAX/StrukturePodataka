#pragma once
#include "SLLNode.h"
using namespace std;

template<class N>
class SLList {
protected:
	SLLNode<N>* head, * tail;
public:
	SLList() {
		head = tail = NULL;
	}
	~SLList();
	bool Prazno() {
		return head == NULL;
	}
	void DodajNaHead(N e);
	void DodajNaTail(N e);
	N ObrisiSaHead();
	N ObrisiSaTail();
	SLLNode<N>* NadjiPtrCvor(N e);
	SLLNode<N>* VratiHead();
	SLLNode<N>* VratiSledeci(SLLNode<N>* ptr);
	N VratiHeadEl();
	N VratiSlElement(N e);
	void Stampaj();
	void ObrisiElement(N e);
	void sort();
	void Update(int oldInfo, int newInfo);
};

template<class N>
SLList<N>::~SLList<N>() {
	while (!Prazno())
		N trenutni = ObrisiSaHead();
}
template<class N>
void SLList<N>::DodajNaHead(N e) {
	head = new SLLNode<N>(e, head);
	if (tail == NULL)
		tail = head;
}
template <class N>
void SLList<N>::DodajNaTail(N e) {
		if (Prazno())
		{
			head = tail = new SLLNode<N>(e);
			return;
		}
		else
		{
			tail->next = new SLLNode<N>(e);
			tail = tail->next;
		}
}
template<class N>
N SLList<N>::ObrisiSaHead() {
	if (Prazno())
		throw new exception("Prazna lista!");
	N e = head->info;
	SLLNode<N>* trenutni = head;
	if (head == tail)
		head = tail = NULL;
	else
		head = head->next;
	delete trenutni;
	return e;
}
template<class N>
N SLList<N>::ObrisiSaTail() {
	if (Prazno())
		throw new exception("Prazna lista!");
	N e = tail->info;
	SLLNode<N>* trenutniZaBrisanje = tail;
	if (head == tail)
		head = tail = NULL;
	else
	{
		SLLNode<N>* trenutniZaObilazak;
		for (trenutniZaObilazak = head; trenutniZaObilazak->next != NULL; trenutniZaObilazak = trenutniZaObilazak->next)
			tail = trenutniZaObilazak;
		tail->next = NULL;
	}
	delete trenutniZaBrisanje;
	return e;
}
template<class N>
SLLNode<N>* SLList<N>::NadjiPtrCvor(N e) {
	if (!Prazno())
		throw new exception("Lista prazna!");
	SLLNode<N>* trenutni = head;
	while (trenutni->info != e)
		trenutni = trenutni->next;
	return trenutni;
}
template<class N>
SLLNode<N>* SLList<N>::VratiHead() {
	if (Prazno())
		throw new exception("Lista prazna!");
	SLLNode<N>* trenutni = head;
	return trenutni;
}
template<class N>
SLLNode<N>* SLList<N>::VratiSledeci(SLLNode<N>* ptr) {
	if (Prazno())
		throw new exception("Lista prazna!");
	SLLNode<N>* trenutni = head;
	while (trenutni != ptr)
		trenutni = trenutni->next;
	return trenutni->next;
}
template<class N>
N SLList<N>::VratiHeadEl() {
	if (Prazno())
		throw new exception("Lista prazna!");
	return head->info;
}
template<class N>
N SLList<N>::VratiSlElement(N e) {
	if (Prazno())
		throw new exception("Lista prazna!");
	SLLNode<N>* trenutni = head;
	while ( trenutni !=NULL && trenutni->info != e)
		trenutni = trenutni->next;
	if (trenutni == NULL)
	{
		cout << "Trazeni broj nije u listi! ";
		return -1;
	}
	else
		return trenutni->next->info;
}
template<class N>
void SLList<N>::Stampaj() {
	cout << "Lista: " << endl;
	for (SLLNode<N>* trenutni = head; trenutni != NULL; trenutni = trenutni->next)
		cout << trenutni->stampajElement() << " ";
	cout << endl;
}
template<class N>
void SLList<N>::ObrisiElement(N e) {
	SLLNode<N>* trenutni = head;
	SLLNode<N>* prethodni = NULL;
	if (Prazno())
		throw new exception("Prazna lista!");
	if (head == tail && head->Jednaki(e))
	{
		delete head;
		head = tail = NULL;
	}
	else if (e == head->info)
	{
		SLLNode<N>* trenutni = head;
		head = head->next;
		delete trenutni;
	}
	else
	{
		while (trenutni != NULL && trenutni->info != e)
		{
			prethodni = trenutni;
			trenutni = trenutni->next;
		}
		prethodni->next = trenutni->next;
		delete trenutni;
	}
}
template<class N>
void  SLList<N>::sort()
{
	SLLNode<N>* trenutni = head;
	int trenutni1;
	int br = 0;
	while (trenutni != NULL)
	{
		br++;
		trenutni = trenutni->next;
	}
	trenutni = head;
	for (int j = 0; j < br; j++)
	{
		while (trenutni->next != NULL)
		{
			if (trenutni->info > trenutni->next->info)
			{
				trenutni1 = trenutni->info;
				trenutni->info = trenutni->next->info;
				trenutni->next->info = trenutni1;

			}
			trenutni = trenutni->next;
		}
		trenutni = head;
	}
}

template<class N>
void SLList<N>::Update(int oldInfo, int newInfo)
{
	SLLNode<N>* trenutni;
	SLLNode<N>* prethodni = NULL;
	SLLNode<N>* pomocni;

	trenutni = head;
	while (trenutni!=NULL && trenutni->info != oldInfo)
	{
		prethodni = trenutni;
		trenutni = trenutni->next;
	}

	if (trenutni == NULL)
		return;
	if (prethodni == NULL)
	{
		trenutni->next = head;
		head = trenutni;
	}

	
	if (trenutni->info == oldInfo)
	{
		trenutni->info = newInfo;
	}
		
	if (prethodni!=NULL && prethodni->info > trenutni->info)
	{
		
		prethodni->next = trenutni->next;
		prethodni = NULL;
		pomocni = head;

		while (pomocni->info < trenutni->info)
		{
			prethodni = pomocni;
			pomocni = pomocni->next;
		}

		if (prethodni == nullptr)
		{
			trenutni->next = head;
			head = trenutni;
		}
		else
		{
			prethodni->next = trenutni;
			trenutni->next = pomocni;
		}	
	}
	else if ( prethodni != NULL && trenutni->info > trenutni->next->info)
	{
		prethodni->next = trenutni->next;
		prethodni = trenutni->next;
		pomocni = trenutni->next->next;

		while (pomocni != nullptr && trenutni->info > pomocni->info)
		{
			prethodni = pomocni;
			pomocni = pomocni->next;
		}

		if (pomocni == nullptr)
		{
			prethodni->next = trenutni;
			trenutni->next = NULL;
		}
		else
		{
			trenutni->next = pomocni;
			prethodni->next = trenutni;
		}
	}
}