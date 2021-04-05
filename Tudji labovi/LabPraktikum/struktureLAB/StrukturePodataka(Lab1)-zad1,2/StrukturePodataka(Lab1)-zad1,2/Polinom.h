#pragma once
#include <iostream>
using namespace std;
#include "Node.h"
class Polinom
{
public:
	Node *head, *tail;
	int max;
public:
	Polinom();
	Polinom(int m);
	Polinom(const Polinom&);
	bool isEmpty();
	void DeleteHead();
	void Print();
	void Coef(int, double);
	Polinom* Add(Polinom, Polinom);
	~Polinom();
	Polinom* Multiply(Polinom, Polinom);

};