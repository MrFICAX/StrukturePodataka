#pragma once
#include <iostream>
using namespace std;


class HashNode
{

public:

	char* key;
	int status;
	int next;

public:


	HashNode()
	{
		
		next =-1;
		status = 0;
	}

	HashNode(char* s)
	{
		key = new char[strlen(s) + 1];
		strcpy(key, s);
		next = -1;
		status = 2;
	
	}

	HashNode(char* s, int n)
	{
		key = new char[strlen(s) + 1];
		strcpy(key, s);
		next = n;
		status = 2;
		
	}

	~HashNode()
	{
		if (key)
			delete key;
	}

	bool isEqual(char* s)
	{
		return strcmp(key, s) == 0;
	}

	bool isFree()
	{
		return status <2;
	}

	void setEl(char* s)
	{
		key = new char[strlen(s) + 1];
		strcpy(key, s);
		next = -1;
		status = 2;
	}

	void setEl(char* s, int n)
	{
		key = new char[strlen(s) + 1];
		strcpy(key, s);
		next = n;
		status = 2;
	}

	void print()
	{

		cout << "KEY: " << key << " STATUS: " << status << " NEXT|: " << next << endl;

	}


};