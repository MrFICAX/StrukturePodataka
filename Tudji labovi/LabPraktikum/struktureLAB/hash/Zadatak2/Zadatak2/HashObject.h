#pragma once
#include <iostream>
using namespace std;



class HashObject 
{

public:
	int brojTelefona;
	char* ime;
	char* prezime;
	HashObject* next;

public:

	HashObject()
	{
		strcpy(ime, "");
		strcpy(prezime, "");
		brojTelefona = 0;
		next = NULL;
	}

	HashObject(char* im,char* prez,int brTel)
	{
		ime = new char[strlen(im) + 1];
		prezime = new char[strlen(prez) + 1];
		strcpy(ime, im);
		strcpy(prezime, prez);
		brojTelefona = brTel;
		next = NULL;
	}

	HashObject(char* im, char* prez, int brTel, HashObject* n)
	{
		ime = new char[strlen(im) + 1];
		prezime = new char[strlen(prez) + 1];
		strcpy(ime, im);
		strcpy(prezime, prez);
		brojTelefona=brTel;
		next = n;
	}

	void deletePretplatnik()
	{
		if (ime)
			delete ime;
		if (prezime)
			delete prezime;
	}
			
	
	~HashObject()
	{
		deletePretplatnik();
	}

	void print()
	{
		cout << ime << " " << prezime <<" "<< brojTelefona<< "; ";
	}

	bool isEqual(char* im,char* prez)
	{
		if (strcmp(ime, im) == 0&&strcmp(prezime,prez)==0)
			return true;
		else
			return false;
	}

	int getBr()
	{
		return brojTelefona;
	}






};