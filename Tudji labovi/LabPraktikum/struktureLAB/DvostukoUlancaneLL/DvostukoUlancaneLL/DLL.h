#pragma once
#include <iostream>
using namespace std;
#include "Node.h"
class DLLista
{
public:
	Node* head;
	Node* tail;
public:
	DLLista();
	~DLLista();
	void addToHead(int);
	void Print();
	void BubbleDvostruke();
	bool isEmpty();
	void addToTail(int);
	void deleteFromHead();
	void deleteFromTail();
};
