#include <iostream>

using namespace std;

class BinarniStatickiHeap {
private:
	int* niz;
	int velicina;
	int brojEl;

public:
	BinarniStatickiHeap();
	BinarniStatickiHeap(int);
	BinarniStatickiHeap(BinarniStatickiHeap& tmp);
	~BinarniStatickiHeap();

	void dodaj(int );
	void brisiKoren();

	BinarniStatickiHeap* KopijaUOgledalu();
	void stampajPoSirini();
	void stampajPoDubini(int);
	bool jePotpuno();
	



};