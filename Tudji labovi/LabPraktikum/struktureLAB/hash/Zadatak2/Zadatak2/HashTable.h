#pragma once
#include "HashObjectLL.h"



class HashTable
{

private:
	HashObjectLL* arr;
	unsigned int length;
	unsigned int count;
	unsigned int h(unsigned int i)
	{
		return(f(i) % length);
	}
	unsigned int f(unsigned int i)
	{
		return (i % 1000+i/1000);
	}

public:

	HashTable(unsigned int l)
	{
		length= l;
		count = 0;
		arr = new HashObjectLL[length];
	}

	~HashTable()
	{
		if (arr)
			delete[]arr;
	}

	void insert(char* a,char* b,int c)
	{
		arr[h(c)].addToHead(a,b,c);
		count++;
	}

	void withdraw(char* a, char*b,int c)
	{
		arr[h(c)].deleteEl(a, b);
		count--;
	}

	void printALL()
	{
		unsigned int i = 0, j = 0;
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


};