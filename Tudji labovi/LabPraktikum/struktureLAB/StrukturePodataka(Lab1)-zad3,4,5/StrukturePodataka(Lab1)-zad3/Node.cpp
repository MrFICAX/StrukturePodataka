#include <iostream>
#include "Node.h"

using namespace std;

Node::Node() : info(0), link(NULL)
{
}

Node::Node(int el) : info(el), link(NULL)
{
}

Node::Node(int el, Node* n) : info(el), link(n)
{
}

Node::~Node()
{
}

bool Node::isEqual(int el)
{
	if (el == info)
		return true;
	else
		return false;
}