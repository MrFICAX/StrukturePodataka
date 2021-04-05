#pragma once
#include <iostream>
using namespace std;



class HashObject
{

public:
	char* ime;
	char* prezime;
	int broj;
	HashObject* next;

public:

	HashObject()
	{
		broj = 0;
		next = NULL;
	}

	HashObject(char* a, char* b, int c)
	{
		ime = new char[strlen(a) + 1];
		prezime = new char[strlen(b) + 1];
		strcpy(ime, a);
		strcpy(prezime, b);
		broj = c;
		next = NULL;
	}

	HashObject(char* a, char* b, int c, HashObject* n)
	{
		ime = new char[strlen(a) + 1];
		prezime = new char[strlen(b) + 1];
		strcpy(ime, a);
		strcpy(prezime, b);
		broj = c;
		next = n;
	}

	~HashObject()
	{
		if (ime)
			delete ime;
		if (prezime)
			delete prezime;
	}

	bool isEqual(char* a, char* b)
	{
		if (strcmp(ime, a) == 0 && strcmp(prezime, b) == 0)
			return true;
		else
			return false;
	}

	void print()
	{

		cout << ime << " " << prezime << " " << broj << " ";

	}







};