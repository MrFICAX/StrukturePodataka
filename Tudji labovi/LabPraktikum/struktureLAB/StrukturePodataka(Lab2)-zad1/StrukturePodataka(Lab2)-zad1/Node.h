#pragma once
#include "HashObject.h"
#include <iostream>
using namespace std;

template< class T >
class Node
{
public:
	T info;
	Node<T>* next;
public:
	Node(){ info = 0; next = NULL; };
	Node(T info){ this->info = info; next = NULL; };
	~Node(){};
	void printNode(){ cout << info; };
};