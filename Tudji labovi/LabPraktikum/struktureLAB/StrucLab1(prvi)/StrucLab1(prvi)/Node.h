#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	double coef;
	int exp;

	Node* link;

	double rcoef() { return coef; }
	int rexp() { return exp; }
	Node()
	{
		coef = 0; exp = 0; link = 0;
	}
	Node(int e, double c)
	{
		exp = e;
		coef = c;
		link = NULL;
	}
	void print()
	{
		cout << "x^(" << exp << ")*" << coef;
	}
	bool isequal(int e, double c)
	{
		return (c == coef && exp == e) ? true : false;
	}
	Node* getnext()
	{
		return this->link;
	}
	void setlink(Node* l)
	{
		link = l;
	}
	~Node()
	{

	}
};