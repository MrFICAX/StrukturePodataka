#include "Cvor.h"
#include <iostream>
using namespace std;
#pragma once
class SDList
{   public:
	int lrmp;
	int head;
	int tail;
	Cvor * polje;
	int max;

public:
	SDList();
	SDList(int x);
	~SDList();
	void AddToHead(int el);
	void Remove(int el);
	void Print();

};