#include "Node.h"
Node::Node()
{
	next = NULL;
	koeficijent = 0;
	stepen = -1;
}
Node::Node(double k, int s)
{
	koeficijent = k;
	stepen = s;
	next = NULL;
}
Node::Node(double k, int s, Node*p)
{
	koeficijent = k;
	stepen = s;
	next = p;
}
double Node::Koef()
{
	return koeficijent;
}
Node::~Node()
{
}
