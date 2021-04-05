#pragma once
#include <iostream>
using namespace std;

class HashNode
{
public:
	char* key;
	bool status;//false slobodan, true zauzet;
public:
	HashNode()
	{
		key = NULL;
	}
	~HashNode()
	{
		if (key)
			delete key;
	}
	void SetEl(char* kljuc)
	{
		key = new char[strlen(kljuc) + 1];
		strcpy(key, kljuc);
		status = true;
	}
	bool isEqual(char* a)
	{
		return strcmp(key, a) == 0;
	}
	void printNode()
	{
		cout << "KEY: " << key << endl;
	}
	bool isFree()
	{
		return status == false;
	}
	void deleteKey()
	{
		if (key)
		{
			delete key;
			status = false;
		}
	}
};