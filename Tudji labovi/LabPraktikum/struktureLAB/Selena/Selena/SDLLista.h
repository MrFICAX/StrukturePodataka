#pragma once
#include "SDNode.h"
#include <iostream>
using namespace std;
class SDLList
{
protected:
	int size;
	int head;
	int tail;
	int lrmp;
	SDNode * data;
public:
	SDLList();
	SDLList(int n);
	~SDLList();
	void printAll( );
	void addToHead(int el);
	void deleteEl(int el);
};
