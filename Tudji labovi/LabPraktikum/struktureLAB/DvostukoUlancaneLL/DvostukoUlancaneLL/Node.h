#pragma once
#include <iostream>
using namespace std;
class Node
{
public:
	int info;
	Node* next;
	Node* prev;
public:
	Node();
	~Node();
	Node(int);
	Node(int, Node*, Node*);
};

