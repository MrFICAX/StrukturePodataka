#include<iostream>
using namespace std;
class Red 
{
	//Koristimo staticku implementaciju reda.
protected:
	int *niz;
	int size;
	int head;//indeks,ne pokazivac!
	int tail;
	int brojTrenutnih;//broj trenutnih
public:
	Red();
	Red(int);
	~Red();
	int getHead();// { return head; } Ovo ne valja!
	void enqueue(int el);
	int dequeue();
	bool isEmpty() { return brojTrenutnih == 0; }
	int vracamBrojElemenata() { return brojTrenutnih; }
	void stampam();
};