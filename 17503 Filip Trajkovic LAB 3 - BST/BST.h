#include "Cvor.h"
#include <iostream>
using namespace std;

class BST {
private:
	Cvor* koren;
	unsigned int broj_el;

public:
	BST();
	~BST();
	void insert(int el);
	Cvor* search(Cvor*, int);
	void deleteTree(Cvor* );
	void printPostOrder();
	void printPostOrder(Cvor* tmp);
	
	void printLevelOrder();
	void printLevelOrder(Cvor* tmp);
	void printGivenLevel(Cvor* tmp, int level);
	int visina(Cvor* node);

	void brisanjeListova();
	void brisanjeListova(Cvor*);
};
