#include "Node.h"


Node::Node()
{
	next = NULL;
	prev = NULL;
}
Node::Node(int a)
{
	info = a;
	next = NULL;
	prev = NULL;
}
Node::Node(int a, Node* n, Node*p)
{
	info = a;
	next = n;
	prev = p;
}

Node::~Node()
{

}
