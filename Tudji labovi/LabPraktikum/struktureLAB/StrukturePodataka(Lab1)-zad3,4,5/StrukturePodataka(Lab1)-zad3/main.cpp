//#include "Node.h"
#include "SortList.h"
#include <iostream>
using namespace std;
void main()
{
	CSortList* lista = new CSortList;
	lista->AddToHead(10);
	lista->AddToHead(5);
	lista->AddToHead(20);
    lista->AddToHead(11);
	lista->AddToHead(202);
	lista->PrintAll();
	lista->Sort3();
	lista->PrintAll();
}