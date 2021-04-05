#include <iostream>
#include "SDList.h"
using namespace std;
void main()
{
	SDList lista(5);
	lista.AddToHead(1);
	lista.AddToHead(2);
	lista.AddToHead(10);
	lista.AddToHead(5);
	lista.AddToHead(4);
	//lista.Remove(10);
	lista.Remove(2);
	lista.Print();



}