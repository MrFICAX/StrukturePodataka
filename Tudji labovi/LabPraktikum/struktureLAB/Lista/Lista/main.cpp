#include <iostream>
#include "Lista.h"


using namespace std;

void main()
{
	List* lista = new List;
	lista->AddToHead(10);
	lista->AddToTail(5);
	lista->AddToTail(20);
	lista->AddToHead(11);
	lista->AddToHead(202);
	lista->PrintAll();
	cout << "Info deo glave liste je: " << lista->GetHeadEl() << endl;
	cout << "Brisanje prvog elementa." << endl;
	cout << "Obrisan je element: " << lista->DeleteFromHead() << endl;
	lista->PrintAll();
	cout << "Info deo glave liste je: " << lista->GetHeadEl() << endl;
	lista->AddToHead(100);
	lista->AddToTail(100);
	lista->PrintAll();
	if (lista->isinList(5))
		cout << "Trazeni element je u listi." << endl;
	else
		cout << "Trazeni element je u listi." << endl;
	lista->DeleteAll();
	if (lista->isEmpty())
		cout << "Lista je prazna!" << endl;
	else
		lista->PrintAll();

	lista->AddToHead(11111);
	lista->PrintAll();
	lista->AddToTail(22222);
	lista->PrintAll();

}