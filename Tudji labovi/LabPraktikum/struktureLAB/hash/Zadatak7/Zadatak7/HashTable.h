#include "HashNode.h"

class HashTable
{
	HashNode* niz;
	unsigned int duz;
	unsigned int count;
private:
	unsigned int f(char* s)
	{
		unsigned int res = 0;
		unsigned int a = 7;
		for (unsigned int i = 0; s[i] != '\0'; i++)
			res = res << a^s[i];
		return res;
	}
	unsigned int h(unsigned int a) //primarna transformacija
	{
		return a%duz;
	}
	unsigned int g(unsigned int i)//modifikovano linearno trazenje
	{
		return  prost()*i;
	}
	unsigned int sekundarna(unsigned int i)
	{
		return (h(i) + g(i)) % duz;
	}
public:
	HashTable(unsigned int l)
	{
		duz = l;
		count = 0;
		niz = new HashNode[duz];
		for (unsigned int i = 0; i < duz; i++)
			niz[i].status = false;
	}
	unsigned int prost()
	{
		for (unsigned int i = 2; i < duz / 2; i++)
		if (duz%i != 0)
			return i;
		return 0;
	}
	void insert(char* k)
	{
		unsigned int hash = h(f(k));
		unsigned int probe = hash;
		if (niz[hash].isFree())
		{
			niz[hash].SetEl(k);
			count++;

		}
		else
		{
			probe = sekundarna(probe);
			while (!niz[probe].isFree())
			{

				probe = sekundarna(probe);
				if (probe == hash)
					throw "Losa sekundarna transformacija";
			}
			niz[probe].SetEl(k);
			count++;

		}
	}
	void print()
	{
		for (unsigned int i = 0; i < duz; i++)
		{
			if (!niz[i].isFree())
			{
				cout << i << ": ";
				niz[i].printNode();
			}
		}
	}

	void withdraw(char* k)
	{
		unsigned int hash = h(f(k));
		unsigned int probe = hash;

		if (niz[hash].isEqual(k))
		{
			cout << hash << ": ";
			niz[hash].printNode();
			niz[hash].deleteKey();
			count--;
		}
		else
		{

			probe = sekundarna(probe);
			while (!niz[probe].isEqual(k))
			{
				probe = sekundarna(probe);
				if (probe == hash)
					throw "Losa sekundarna transformacija";
			}
			cout << probe << ": ";
			niz[probe].printNode();
			niz[probe].deleteKey();
			count--;
		}
	}
};