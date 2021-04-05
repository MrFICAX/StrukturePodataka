#pragma once
#include <iostream>
#include<stdlib.h>
using namespace std;


class HashNode
{

public:
	char* ime;
	char* prezime;
	int broj;
	bool status;


public:

	HashNode()
	{
		ime = NULL;
		prezime = NULL;
		broj = 0;
		status = true;
	}

	~HashNode()
	{
		if (ime)
			delete ime;
		if (prezime)
			delete prezime;
	}


	void setEl(char* a, char* b, int c)
	{
		ime = new char[strlen(a) + 1];
		prezime = new char[strlen(b) + 1];
		broj = c;
		strcpy(ime, a);
		strcpy(prezime, b);
		status = false;
	}

	bool isFree()
	{
		return status == true;
	}

	bool isEqual(int a)
	{
		return broj == a;
	}

	void deleteEl()
	{
		if (ime)
			delete ime;
		if (prezime)
			delete prezime;
		broj = 0;
		status = true;
	}

	void print()
	{
		cout << "IME: " << ime << "|| PREZIME: " << prezime << "|| BROJ: " << broj << endl;
	}
};