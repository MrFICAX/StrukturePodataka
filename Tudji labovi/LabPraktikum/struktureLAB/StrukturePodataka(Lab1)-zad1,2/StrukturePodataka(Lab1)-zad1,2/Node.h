#include <iostream>
#pragma once
using namespace std;
class Node
{
public:
	double koeficijent;
	int stepen;
	Node* next;
public:
	Node();
	~Node();
	Node(double x, int y);
	Node(double x, int y, Node * z);
	double Koef();
};