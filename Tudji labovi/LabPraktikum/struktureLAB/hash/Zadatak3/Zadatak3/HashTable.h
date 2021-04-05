#pragma once
#include "HashNode.h"



class HashTable
{
private:
	int length;
	int count;
	HashNode* arr;
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
		return i%length;
	}
	unsigned int g(unsigned int i)
	{
		return (i + 1) % length;
	}

public:
	
	HashTable(int l)
	{
		length = l;
		count = 0;
		arr = new HashNode[length];
	}

	~HashTable()
	{
		if (arr)
			delete[] arr;
	}

	void insert(char* s)
	{
		if (count == length)
			throw "Full!";
		long plc = h(f(s));
		if (!arr[plc].isFree())
		{
			while (arr[plc].next != -1)
				plc = arr[plc].next;
			long tmp = plc;
			plc = g(plc);
			while (!arr[plc].isFree() && plc != tmp)
				plc = g(plc);
			if (plc == tmp)
				throw "Error in transform!";
			arr[tmp].next = plc;
		}
		arr[plc].setEl(s, -1);
		count++;
	}

	unsigned int find(char* k)
	{
		long tmp = h(f(k));
		while (tmp != -1)
		{
			if (!arr[tmp].isEqual(k))
				tmp = arr[tmp].next;
			else
				return tmp;
		}
		return -1;
	}

	void print()
	{
		for (int i = 0; i<length; i++)
		if (!arr[i].isFree())
		{
			cout << i << ":";
			arr[i].print();
		}
	}



};