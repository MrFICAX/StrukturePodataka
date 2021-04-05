#include "Node.h"


Node::Node()
{
	info = -1;
	i = 0;
	j = 0;
	linkk = NULL;
	linkv = NULL;
}
Node::Node(int a, int b, int c, Node* p1, Node* p2)
{
	i = a;
	j = b;
	info = c;
	linkv = p1;
	linkk = p2;
}
void Node::print(){
	cout << "[" << i << "," << j << "]" << "=" << info << "  ";
}
Node::~Node()
{
}