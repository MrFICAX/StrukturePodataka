#pragma once
#include "HashObjectLL.h"


class HashTable
{
private:
	int length;
	int count;
	HashObjectLL* arr1;
	int additional;
	int f(int i)
	{
		return(i % 1000 + i / 1000);
	}
	int h(int i)
	{
		return i%length;
	}

public:

	HashTable(int l, int i)
	{
		length = l;
		count = 0;
		additional = i;
		arr1 = new HashObjectLL[length + additional];
	}

	~HashTable()
	{
		if (arr1)
			delete[] arr1;
	}

	void insert(char* a,char* b,int c)
	{
		if (arr1[h(f(c))].isEmpty())
			arr1[h(f(c))].addToHead(a, b,c);
		else
		{
			int pok = length+h(f(c));
			arr1[pok].addToHead(a, b, c);
		}
		count++;
	}

	void withdraw(char* a, char* b, int c)
	{
		if (arr1[h(f(c))].isEqual1(a, b))
		{
			if (arr1[h(f(c))].deleteEl(a, b))
				count--;
		}
		else
		{
			int pok = length+h(f(c));
			if (arr1[pok].deleteEl(a, b))
				count--;
		}
			
		
		
	}

	void printALL()
	{
		 int i = 0, j = 0;
		while (i < count && j<length+additional)
		{
			if (!arr1[j].isEmpty())
			{
				cout << j << ": ";
				arr1[j].print();
				i++;
			}
			j++;
		}
	}





};