#include <iostream>
using namespace std;
#include "Node.h"
#include "Polinom.h"

void main()
{
	Polinom a(4);
	a.Coef(4, 2);
	a.Coef(3, 6);
	a.Coef(2, 5);
	a.Coef(1, 8);
	a.Coef(0, 24);
	a.Print();
	Polinom b(3);
	b.Coef(3, 4);
	b.Coef(2, 5);
	b.Coef(1, 2);
	b.Coef(0, 6);
	b.Print();
	int z;
	if (a.max > b.max)
		z = a.max;
	else
		z = b.max;
	Polinom c(z);
	Polinom pol(a);
	pol.Print();
	Polinom *d;
	d = c.Add(a, b);
	d->Print();
	Polinom *g;
	int k;
	k = a.max + b.max;
	Polinom j(k);
	Polinom *i;
	i = j.Multiply(a, b);
	i->Print();
}