#pragma once
#include <iostream>
#pragma once
#include "HashNode.h"
class BirackiSpisak
{
	HashNode * niz;
	int length;
	int count;
public:
	unsigned int f(char* s)
	{
		unsigned int res = 0;
		unsigned int a = 7;
		for (int i = 0; s[i] != '\0'; i++)
			res = res << a^s[i];
		return res;
	}
	unsigned int h(unsigned int i)
	{
		return (i / 10000+ i % 10000) % length;
	}
	unsigned int g(int i)
	{
		return i*i;
	}
	unsigned int s(unsigned int i) 
	{
		return ((h(i) + g(i)) % length);
	}
	BirackiSpisak(int duz)
	{
		length = duz;
		niz = new HashNode[length];
		count = 0;
		for (int i = 0; i < length; i++)
			niz[i].status = 2;
	}
	~BirackiSpisak()
	{
		if (niz != 0)
			delete[] niz;
	}
	void insert(char* k,char *q,char *p)
	{
		unsigned int hash = h(f(k));
		unsigned int probe = hash;
		if (niz[hash].isFree())
		{
			niz[hash].SetEL(k,q,p);
			count++;
		}
		else
		{
			probe = s(probe);
			while (!niz[probe].isFree())
			{

				probe = s(probe);
				if (probe == hash)
					throw "Losa sekundarna transformacija";
			}
			niz[probe].SetEL(k,q,p);
			count++;

		}
	}
	void print()
	{
		for ( int i = 0; i < length; i++)
		{
			if (!niz[i].isFree())
			{
				cout << i << ": ";
				niz[i].Print();
			}
			else
				cout << ":";
		}
	}
	void Delete(char *k)
	{
		unsigned int hash = h(f(k));
		unsigned int probe = hash;

		if (niz[hash].isEqual(k))
		{
			cout << hash << ": ";
			niz[hash].Print();
			niz[hash].deleteKey();
			count--;
		}
		else
		{

			probe = s(probe);
			while (!niz[probe].isEqual(k))
			{
				probe = s(probe);
				if (probe == hash)
					throw "Losa sekundarna transformacija";
			}
			cout << probe << ": ";
			niz[probe].Print();
			niz[probe].deleteKey();
			count--;
		}
	}
};