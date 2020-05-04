#pragma once 
#include <iostream>
using namespace std;

class Cvor {
public:
	int kljuc;
	Cvor* levi;
	Cvor* desni;

	Cvor();
	Cvor(int);
	Cvor(int, Cvor*, Cvor*);

	bool jeManji(int el);
	bool jeVeci(int el);
	bool jeJednak(int el);
	void postaviKljuc(int el);
	int vratiKljuc();
	void stampajKljuc();

    Cvor* getLevi();
    void setLevi(Cvor* levi);

    Cvor* getDesni();
    void setDesni(Cvor* desni);

};
