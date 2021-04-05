#pragma once
#include<iostream>
using namespace std;
#include<string.h>

class Izuzetak
{
private:
	char *tekst;
public:
	Izuzetak(char *t){ strcpy(tekst, t); }
	~Izuzetak(){}
	void Print(){ cout << tekst << endl; }
};