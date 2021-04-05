#pragma once
#include <iostream>
#include<stdlib.h>
using namespace std;


class HashNode 
{

public:
	char* ime;
	char* prezime;
	char * JMBG; 
	int status;
	HashNode()
	{
		ime = NULL;
		prezime = NULL;
		JMBG = NULL;
		status = 0;
	}
	~HashNode()
	{ 
		if (ime)
			delete[] ime;
		if (prezime)
			delete[] prezime;
		if (JMBG)
			delete[] JMBG;
	}
	void SetEL(char * a, char * b, char * c)
	{
		JMBG = new char[strlen(a) + 1];
		strcpy(JMBG, a);
		ime = new char[strlen(b) + 1];
		strcpy(ime, b);
		prezime = new char[strlen(c) + 1];
		strcpy(prezime, c);
		status = 2;
	}
	int isFree()
	{
		return status = 0;
	}
	bool isEqual(char * el)
	{
		return strcmp(JMBG, el);
	}
	void DeleteEL()
	{
		if (ime)
			delete[] ime;
		if (prezime)
			delete[] prezime;
		if (JMBG)
			delete[] JMBG;
		status = 1;
	}
	void deleteKey()
	{
		if (JMBG)
		{
			delete [] JMBG;
			status = 1;
		}
	}
	void Print()
	{
		cout << "IME:" << ime << "PREZIME:" << prezime << "JMBG:" << JMBG << endl;
	}


		};