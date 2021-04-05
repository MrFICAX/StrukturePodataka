#pragma once
#include"SLLista.h"

class ChainedHashTable
{
protected:
	int length;
	int count;
	SLList *array;
public:
	ChainedHashTable(int n)
	{
		length = n;
		count = 0;
		array = new SLList[length];
	}

	~ChainedHashTable()
	{
		for (int i = 0; i < length; i++)
			while (!array[i].IsEmpty())
				array[i].DeleteFromHead();
		delete[] array;
	}

	unsigned int h(HashObject obj)
	{
		return obj.GetKey() % 20;  //tu se menja
	}

	//
	unsigned int h1(HashObject obj)
	{
		int p = 5;
		int w = 32;
		int a = 2654435769;
		return (obj.GetKey()*a >> (w - p));
	}
	//
	void Insert(HashObject obj)
	{
		array[h1(obj)].AddToHead(obj);
		count++;
	}

	void Withdraw(HashObject obj)
	{
		array[h(obj)].DeleteEl(obj);
		count--;
	}

	void Print()
	{
		for (int i = 0; i < length; i++)
		{
			array[i].Print();
			cout << endl;
		}
	}
};