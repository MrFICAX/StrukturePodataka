#pragma once
#include<iostream>
using namespace std;

class HashNode
{
public:
	char* key;
	int status; //0-slobodan, 1-obrisan, 2-zauzet
	int next;

public:
	HashNode()
	{
		key = NULL;
		next = -1;
		status = 0;
	}
	HashNode(char* a)
	{
		key = new char[strlen(a) + 1];
		strcpy(key, a);
		next = -1;
		status = 2;
	}
	HashNode(char* a, int n)
	{
		key = new char[strlen(a) + 1];
		strcpy(key, a);
		next = n;
		status = 2;
	}
	~HashNode()
	{
		if (key)
			delete key;
		status = 1;
	}
	bool isEqual(char* a)
	{
		if (strcmp(key, a) == 0)
			return 1;
		return 0;
	}
	bool isFree()
	{
		return status == 0;
	}
	void setEl(char* a)
	{
		key = new char[strlen(a) + 1];
		strcpy(key, a);
		status = 2;
	}
	void setEl(char* a, int n)
	{
		
		key = new char[strlen(a) + 1];
		strcpy(key, a);
		status = 2;
		next = n;
	}
	void print()
	{
		cout << key << "| Status:" << status << "| Next:" << next << endl;
	}
};