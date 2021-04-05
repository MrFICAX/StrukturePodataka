#pragma once

class Node                  //Kreiramo klasu Node(Cvor) kojoj ce biti predstavljen 1 cvor u listi
{
public:
	int info;				//info -> predstavlja data/vrednost, tj. neki podatak koji cuva cvor
	Node* link;				// info deo nam je tipa int, ali moze biti kog drugog ugradjenog ili korisnickog tipa
public:						// link tipa Node* (pointer) --> To je u stvari pokazivac na svaki sledeci cvor u listi
	Node();
	Node(int el);
	Node(int el, Node* n);
	~Node();
	inline int print() { return info; }
	bool isEqual(int el);
};