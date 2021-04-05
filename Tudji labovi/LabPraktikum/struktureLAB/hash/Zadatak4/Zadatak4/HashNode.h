#pragma once
#include <iostream>
using namespace std;


class HashNode
{
public:

	char* ime;
	char* prezime;
	int broj;
	int next;
	int status;

public:

	HashNode()
	{

		broj = 0;
		next = -1;
		status = 0;
	}

	~HashNode()
	{
		if (ime)
			delete ime;
		if (prezime)
			delete prezime;
		status = 1;
	}

	void setEl(char*a, char*b, int c)
	{
		ime = new char[strlen(a) + 1];
		prezime = new char[strlen(b) + 1];
		strcpy(ime, a);
		strcpy(prezime, b);
		broj = c;
		next = -1;
		status = 2;
	}

	void setEl(char*a, char*b, int c, int n)
	{
		ime = new char[strlen(a) + 1];
		prezime = new char[strlen(b) + 1];
		strcpy(ime, a);
		strcpy(prezime, b);
		broj = c;
		next = n;
		status = 2;
	}

	void print()
	{
		cout << ime << " " << prezime << " " << broj << " |NEXT: " << next << endl;
	}

	bool isFree()
	{
		return status < 2;
	}

	bool isEqual(int a)
	{
		return a == broj;
	}






};