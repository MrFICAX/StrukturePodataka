#pragma once
#include<iostream>
using namespace std;
class DvostraniRed 
{
public:
	int velicina;
	int *niz;
	int head, tail;
	int trenutniBroj;

	DvostraniRed();
	DvostraniRed(int);
	~DvostraniRed();
	int getHead();
	int getTail();
	void enqueueHead(int);
	void enqueueTail();
	void dequeueHead();
	void dequeueTail();
	bool isEmpty();
	int brojElemenata() { return trenutniBroj; }
	

};