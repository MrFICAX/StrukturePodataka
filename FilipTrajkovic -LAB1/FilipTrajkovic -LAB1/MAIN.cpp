#include <iostream>
#include "SLList.h"
#include "SLLNode.h"
#include <string.h>
using namespace std;
int main() {
	try {
		SLLNode<int>* tmp ;
		SLList<int>* NovaLista = new SLList<int>();
		for(int i=5;i<15;i++)
		NovaLista->DodajNaHead(i);
		NovaLista->sort(); 
		NovaLista->Stampaj();
		NovaLista->DodajNaTail(33);
		NovaLista->ObrisiSaHead();
		NovaLista->sort();
		NovaLista->Stampaj();
		cout << "Vracen element preko pointera: " << endl;
		tmp = NovaLista->VratiHead();
		cout << tmp->info << endl;
		NovaLista->Stampaj();

		NovaLista->Update(6, 15);
	

		NovaLista->sort();
	NovaLista->Stampaj();
		
		NovaLista->Update(7, 16);
		NovaLista->sort();
		NovaLista->Stampaj();
		
		NovaLista->Update(8, 17);
		NovaLista->sort();
	NovaLista->Stampaj();
	}
	catch (string* g)
	{
		cout << g;
	}
	return 0;
}