#pragma once
#include "HashNode.h"

class HashTable
{
	HashNode* niz;
	int length;
	int count;
private:
	unsigned int h(unsigned int i)//primarna transformacija (metod presavijanja)
	{
		return (i / 1000 + i % 1000) % length; //i/1000 prve 4 cifre i po % 1000 3 cifre 
	}
	unsigned int g(int i)
	{
		return prost()*i*i;
	}
	unsigned int prost()
	{
		for (int i = 2; i < length / 2; i++)
		if (length%i != 0)
			return i;
		return 0;
	}
	unsigned int f(unsigned int i) //sekundarna transformacija(mod.lin.trazenje)
	{
		return ((h(i) + g(i)) % length);
	}
public:
	HashTable(int l)
	{
		length = l;
		niz = new HashNode[length];
		count = 0;
		for (int i = 0; i < length; i++)
			niz[i].status = true;
	}
	~HashTable()
	{
		if (niz)
			delete[] niz;
	}
	void insert(char* a, char*b, int c)
	{
		unsigned int hash = h(c);
		unsigned int probe = hash;
		if (niz[hash].isFree())
		{
			niz[hash].setEl(a, b, c);
			count++;
		}
		else
		{
			probe = f(probe);
			while (!niz[probe].isFree())
				probe = f(probe);
			if (probe == hash)
				throw "Losa sekundarna transformacija";
			niz[probe].setEl(a, b, c);
			count++;
		}
	}
	void withdraw(int c)
	{
		unsigned int hash = h(c);
		unsigned int probe = hash;
		if (niz[hash].isEqual(c))
		{
			cout << "[" << hash << "]";
			niz[hash].print();
			niz[hash].deleteEl();
			count--;
		}
		else
		{
			probe = f(probe);
			while (!niz[probe].isEqual(c))
				probe = f(probe);
			if (niz[probe].isEqual(c))
			{
				cout << "[" << probe << "]";
				niz[probe].print();
				niz[probe].deleteEl();
				count--;
			}
		}
	}
	void printTable()
	{
		for (int i = 0; i < length; i++)
		if (!niz[i].isFree())
		{
			cout << "[" << i << "] ";
			niz[i].print();
		}
	}
};