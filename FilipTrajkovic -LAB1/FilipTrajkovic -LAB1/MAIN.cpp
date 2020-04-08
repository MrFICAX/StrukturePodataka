#include <iostream>
#include "SLList.h"
#include "SLLNode.h"
#include <string.h>
using namespace std;
int main() {
	try {
		SLLNode<int>* tmp ;
		int tmp1;
		SLList<int>* NovaLista = new SLList<int>();
		for(int i=15;i>5;i--)
		NovaLista->DodajNaHead(i);
		NovaLista->Stampaj();
		NovaLista->ObrisiSaTail();
		NovaLista->Stampaj();

		NovaLista->Update(8, 4);
		NovaLista->Stampaj();
	
		NovaLista->Update(10, 15);
		NovaLista->Stampaj();

		NovaLista->Update(7, 16);
		NovaLista->Stampaj();

		NovaLista->Update(9, 17);
		NovaLista->Stampaj();
		cout << "------------------------" << endl;
		cout << "DODAVANJE NA TAIL" << endl;
		NovaLista->DodajNaTail(2); 
		NovaLista->Stampaj();
	
		cout << "DODAVANJE NA TAIL" << endl;
		NovaLista->DodajNaTail(33);
		NovaLista->Stampaj();

		cout << "Lista sa obrisanim elementom:" << endl;
		NovaLista->ObrisiElement(12);
		NovaLista->Stampaj();

		cout << "Vracen sledeci element: " << endl;
		cout << NovaLista->VratiSlElement(13) << endl;
		
		
		cout << "Vracen sledeci element preko pointera: " << endl;
		tmp1 = NovaLista->VratiHead()->next->info;
		cout << tmp1 << endl;

		cout << "Vracen element sa head-a: " << endl;
		tmp = NovaLista->VratiHead();
		cout << tmp->info << endl;
	
	}
	catch (string* g)
	{
		cout << g;
	}
	return 0;
}