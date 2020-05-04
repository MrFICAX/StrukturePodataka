#include "BST.h"
#include "Cvor.h"
#include <iostream>
using namespace std;

void main() {

	BST* stablo = new BST();
	stablo->insert(5);
	stablo->insert(10);
	stablo->insert(4);
	stablo->insert(15);
	stablo->insert(25);
	stablo->insert(123);
	stablo->insert(13);
	stablo->insert(12);
	stablo->printPostOrder();
	cout << "----------------" << endl; //Razdvojeno radi bolje preglednosti
	stablo->printLevelOrder();
	cout << "----------------" << endl; //Razdvojeno radi bolje preglednosti
	stablo->brisanjeListova();
	stablo->printLevelOrder();
	cout << "----------------" << endl; //Razdvojeno radi bolje preglednosti
	stablo->brisanjeListova();
	stablo->printLevelOrder();
	
}