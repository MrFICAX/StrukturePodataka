#pragma once
#include "HashNode.h"



class HashTable
{
private:
	unsigned int length;
	unsigned int count;
	HashNode* arr;
	unsigned int f(int a)
	{
		return(a % 100 + a / 100) % length;
	}
	unsigned int g(int a)
	{
		return (a + 1) % length;
	}

public:

	HashTable(unsigned int l)
	{
		count = 0;
		length = l;
		arr = new HashNode[length];

	}

	~HashTable()
	{
		if (arr)
			delete[] arr;
	}

	void setEl(char* a, char*b, int c)
	{
		if (count == length)
			throw "FULL";
		long plc = f(c);
		if (!arr[plc].isFree())
		{
			while (arr[plc].next != -1)
				plc = arr[plc].next;
			long tmp = plc;
			plc = g(plc);
			while (!arr[plc].isFree() && plc != tmp)
				plc = g(plc);
			if (plc == tmp)
				throw "ERROR!! Something wrong with second transformation!!";
			arr[tmp].next = plc;
		}
		arr[plc].setEl(a, b, c);
		count++;
	}

	unsigned int find(int k)
	{
		long tmp = f(k);
		while (tmp != -1)
		{
			if (!arr[tmp].isEqual(k))
				tmp = arr[tmp].next;
			else
				return tmp;
		}
		return -1;
	}

	void printAll()
	{
		for (unsigned int i = 0; i < length; i++)
		if (!arr[i].isFree())
		{
			cout << i << ". ";
			arr[i].print();
		}
		cout << endl;
	}


};