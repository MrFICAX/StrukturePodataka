#include <iostream>
#include "SDLLista.h"
using namespace std;
void main()
{
	SDLList lista(5);
	lista.addToHead(1);
	lista.addToHead(2);
	lista.addToHead(10);
	lista.addToHead(5);
	lista.addToHead(4);
	lista.printAll();



}