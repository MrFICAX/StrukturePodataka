#pragma once
#include <iostream>
using namespace std;
#include "Node.h"
class Matrica
{
public:
	Node** vrste;
	Node** kolone;
	int dim;
	int brel = 0;
public:
	Matrica();
	~Matrica();
	Matrica(int);
	void SetAt(int, int, int);
	void Print();
};