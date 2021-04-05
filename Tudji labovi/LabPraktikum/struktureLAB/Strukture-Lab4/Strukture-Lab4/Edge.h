#pragma once
#include <iostream>
using namespace std;
#include "Node.h"

class Edge {

public:
	Node *dest;
	Edge *link;
	int weight;
	Edge();
	Edge(Node *d, Edge *l);
	Edge(Node *d, Edge *l, int w);
	~Edge() { }
};
Edge::Edge()
{
	this->dest = NULL;
	this->link = NULL;

}

Edge::Edge(Node *d, Edge *l)
{
	this->dest = d;
	this->link = l;
}

Edge::Edge(Node *d, Edge *l, int w)
{
	this->dest = d;
	this->link = l;
	this->weight = w;
}