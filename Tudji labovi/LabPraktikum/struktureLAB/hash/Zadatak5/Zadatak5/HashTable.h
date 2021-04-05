#pragma once
#include "HashNode.h"



class HashTable
{

private:

	int length;
	int count;
	HashNode* arr1;
	HashNode* arr2;

	unsigned int f(char *i)
	{
		unsigned int res = 0;
		unsigned int a = 7;
		for (int j = 0; j < i[j] != '\0'; j++)
			res = res << a^i[j];
		return res;
	}//deo primarne transformacije
	unsigned int h(unsigned int i)
	{
		return i%length;
	}//p[rimarna transformacija



public:

	HashTable(int l)
	{
		length = l;
		count = 0;
		arr1 = new HashNode[length];
		arr2 = new HashNode[length];
	}

	~HashTable()
	{
		if (arr1)
			delete[] arr1;
		if (arr2)
			delete[] arr2;
	}

	void insert(char* k)
	{
		if (count == length)
			throw "FULL!!";
		long poz = h(f(k));
		if (arr1[poz].isFree())
			arr1[poz].setEl(k);
		else
		{
			long pkz = 0;
			while (!arr2[pkz].isFree())
				pkz++;
			if (arr1[poz].next == -1)
				arr1[poz].next = pkz;
			else
			{
				int pok = 0;
				while (arr2[pok].next != -1)
					pok=arr2[pok].next;
				arr2[pok].next = pkz;
			}
			arr2[pkz].setEl(k);
		}



			


	}
	void print()
	{
		for (int i = 0; i < length; i++)
		{
			if (!arr1[i].isFree())
			{
				cout << i << ":";
				arr1[i].print();
				int a = arr1[i].next;
				while (a != -1&&!arr2[a].isFree())
				{
					cout << a << " ";
					arr2[a].print();
					a = arr2[a].next;
				}
			}
		}
	}
	
};