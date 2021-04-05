#pragma once

#include<iostream>
using namespace std;

class Cvor
{
public:
	int info;
	Cvor* next;

public:
	Cvor();
	Cvor(int);
	Cvor(int, Cvor*);
	~Cvor() {}

	void setInfo(int i) { info = i; }
	void setNext(Cvor* n) { next = n; }
	int getInfo() { return info; }
	Cvor* getNext() { return next; }
	void print() { cout << info << " "; }


};