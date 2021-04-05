#pragma once
#include <iostream>
using namespace std;
class Node
{
public:
	int i, j;
	Node* linkv;
	Node* linkk;
	int info;
public:
	Node();
	~Node();
	Node(int, int, int, Node*, Node*);
	void print();
};