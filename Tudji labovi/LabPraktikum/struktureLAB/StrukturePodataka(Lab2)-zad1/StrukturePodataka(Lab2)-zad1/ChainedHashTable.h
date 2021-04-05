#pragma once
using namespace std;
#include "SLLista.h"

template< class T, class R >
class ChainedHashTable
{
protected:
	unsigned int lenght; //velicina tablice
	unsigned int count; //broj elemenata u tablici
	SLList< HashObject >* niz;
public:
	ChainedHashTable(unsigned int len);
	~ChainedHashTable();
	unsigned int h(char* s);
	void insert(HashObject obj);
	void withdraw(HashObject  obj);
	void printTable();
};

template< class T, class R >
ChainedHashTable<T, R>::ChainedHashTable(unsigned int len)
{
	lenght = len;
	count = 0;
	niz = new SLList< HashObject  >[len];
};

template<class T, class R >
ChainedHashTable<T, R>::~ChainedHashTable()
{
	for (unsigned int i = 0; i<lenght; i++)
		while (!niz[i].isEmpty()) niz[i].deleteFromHead();

	delete[] niz;
};

template<class T, class R>
unsigned int ChainedHashTable<T, R>::h(char* s)
{
	unsigned res = 0;
	unsigned int a = 1;
	for (int i = 0; s[i] != 0; i++)
		res = res << a ^ s[i];
	return res%lenght;
};

template< class T, class R >
void ChainedHashTable<T, R>::insert(HashObject obj)
{
	niz[h(obj.key)].addToHead(obj);
	count++;
};

template< class T, class R >
void ChainedHashTable<T, R>::withdraw(HashObject obj)
{
	niz[h(obj.key)].deleteEl(obj);
	count--;
};

template< class T, class R >
void ChainedHashTable<T, R>::printTable()
{
	for (unsigned int i = 0; i<lenght; i++)
	{
		Node<HashObject>  * tmp;
		for (tmp = niz[i].head; tmp != NULL; tmp = tmp->next)
			tmp->printNode();
		cout << endl;
	}
};