#include"Cvor.h"

Cvor::Cvor() 
{
	info = 0;
	next = NULL;
}
Cvor::Cvor(int a)
{
	info = a;
	next = NULL;
}
Cvor::Cvor(int a, Cvor* c)
{
	info = a;
	next = c;
}

