#pragma once
#include "Edge.h"
#include <iostream>
using namespace std;
class Edge;
class Node {

public:
	int info;
	Edge *adj;
	Node *next;
	int status;

	Node();
	Node(int i);
	Node(int i, Edge *a, Node *n, int s);
	~Node() { }
	void visit() { cout << info << endl; }

};

Node::Node()
{
	this->status = 0;
	this->adj = NULL;
	this->next = NULL;
}

Node::Node(int i)
{
	this->info = i;
	this->adj = NULL;
	this->next = NULL;
	this->status = 0;
}

Node::Node(int i, Edge *a, Node *n, int s)
{
	this->info = i;
	this->adj = a;
	this->next = n;
	this->status = s;
}