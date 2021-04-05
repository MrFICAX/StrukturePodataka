#include <iostream>
using namespace std;
#include "Node.h"
#include "DLL.h"
void main()
{
	DLLista Lista;
	Lista.addToHead(10);
	Lista.addToHead(20);
	Lista.addToHead(30);
	Lista.addToHead(40);
	Lista.addToHead(50);
	Lista.Print();
	Lista.BubbleDvostruke();
	Lista.Print();
	Lista.addToTail(99);
	Lista.addToTail(100);
	Lista.Print();
	Lista.deleteFromHead();
	Lista.deleteFromHead();
	Lista.Print();
	Lista.deleteFromTail();
	Lista.Print();





}