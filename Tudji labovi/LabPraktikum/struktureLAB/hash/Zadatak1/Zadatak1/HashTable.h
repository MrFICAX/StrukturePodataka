#pragma once
#include "HashObjectLL.h"


class HashTable
{
private:

	HashObjectLL* arr;
	int length;
	int count;

public:

	HashTable(int l)
	{
		length = l;
		count = 0;
		arr = new HashObjectLL[length];
	}

	~HashTable()
	{
		if (arr)
			delete[] arr;
	}

	void insert(char* obj)
	{
		if (count == length - 1)
			throw "Stack overflow!";
		arr[h(obj)].addToHead(obj);
		count++;
	}

	void withdraw(char* obj)
	{
		if (count == 0)
			throw "Stack underflow!!";
		if (arr[h(obj)].deleteEL(obj))
			count--;
	}

	void printALL()
	{
		int i = 0, j = 0;
		while (i < count && j<length)
		{
			if (!arr[j].isEmpty())
			{
				cout << j << ": ";
				arr[j].print();
				i++;
			}
			j++;
		}
	}

	HashObject* find(char* obj)
	{
		HashObject* tmp;
		tmp = arr[h(obj)].find(obj);
		return tmp;
	}

private:

	unsigned int f(char* s)
	{
		unsigned int res = 0;
		unsigned int a = 7;
		for (int i = 0; i < s[i] != '\0'; i++)
			res = res << a^s[i];
		return res;
	}

	unsigned int h(char*s)
	{
		return (f(s) % length);
	}


};