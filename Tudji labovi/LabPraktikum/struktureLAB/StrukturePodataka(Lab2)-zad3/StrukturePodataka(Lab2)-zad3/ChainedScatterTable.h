#pragma once
#include"HashTable.h"
#include"ChainedScatterObject.h"
#include"Izuzetak.h"

class ChainedScatterTable : public HashTable
{
protected:
	ChainedScatterObject *array;
public:
	ChainedScatterTable(unsigned int len)
	{
		length = len;
		count = 0;
		array = new ChainedScatterObject[len];
		for (int i = 0; i < length; i++)
		{
			array[i] = ChainedScatterObject();
			array[i].free = true;
			array[i].next = -1;
		}
	}

	~ChainedScatterTable()
	{
		delete array;
	}

	void Display()
	{
		for (unsigned int i = 0; i < length; i++)
			if (!array[i].free)
			{
				cout << "[" << i << "]" << "|";
				array[i].Print();
				cout << "[" << i << "]" << endl;
			}
			else
				cout << "[" << i << "]" << endl;
	}

	void Insert(ChainedScatterObject obj)
	{
		if (count == GetLength())
			throw Izuzetak("Tabela je puna");
		long probe = h(obj);
		if (!array[probe].free)
		{
			while (array[probe].next != -1)
				probe = array[probe].next;
			long tail = probe;
			probe = g(probe);
			while (!array[probe].free && probe != tail)
				probe = g(probe);
			if (probe == tail)
				throw Izuzetak("Losa sekundarna funkcija");
			array[tail].next = probe;
		}
		array[probe] = obj;
		array[probe].free = false;
		array[probe].next = -1;
		count++;
	}

	ChainedScatterObject find(char* key)
	{
		long probe = f(key) % length;
		while (probe != -1)
		{
			if (!array[probe].IsEqualKey(key))
				probe = g(probe);
			return array[probe];
		}
		throw Izuzetak("Element nije nadjen");
	}

	void Withdraw(char* key)
	{
		if (count == 0)
			throw Izuzetak("Tabela je prazna");
		long probe = f(key) % length;
		long prev = -1;
		while (probe != -1 && array[probe].IsEqualKey(key))
		{
			prev = probe;
			probe = array[probe].next;
		}
		if (probe == -1)
			throw Izuzetak("Element nije pronadjen");
		if (prev != -1)//brise se sinonim
		{
			array[prev].next = array[probe].next;
			array[probe].free = true;
		}
		else
		{
			if (array[probe].next == -1)
			{
				array[probe].free = true;
			}
			else
			{
				long nextEl = array[probe].next;
				array[probe] = array[nextEl];
				array[probe].next = array[nextEl].next;
				array[nextEl] = ChainedScatterObject();
				array[nextEl].free = true;
			}
		}
		count--;
	}
};