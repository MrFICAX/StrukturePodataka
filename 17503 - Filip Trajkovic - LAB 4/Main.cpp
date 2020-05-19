#include "GrafKaoLista.h"

using namespace std;

int main() {
	GrafKaoLista<int>* g = new GrafKaoLista<int>();

	int a = 5, b=4, c = 3, d = 10, f= 30;
	g->insertNode(a);
	g->insertNode(b);
	g->insertNode(c);
	g->insertNode(d);
	g->insertNode(f);

	g->insertEdge(a, b);
	g->insertEdge(f, c);
	g->insertEdge(f, f);
	g->insertEdge(b, c);
	g->insertEdge(a, c);
	g->insertEdge(b, a);
//	g->insertEdge(c, b); //bez ove grane je simuliran prolaz preko suseda, sa ovom granom je trivijalan i direktan put od 3 do 4 
	g->insertEdge(a, d);
	g->insertEdge(c, a);

	g->print();
	g->brNeusmerenih();
	
	if(g->minGraf(5, 5));
	if (g->minGraf(30, 30));
	if (g->minGraf(5, 10));
	if (g->minGraf(10, 4));
	if (g->minGraf(3, 4));

	g->breadthTrav(30);
	return 0;
}
