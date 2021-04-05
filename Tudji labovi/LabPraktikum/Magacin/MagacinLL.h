#include"Cvor.h"
#include<iostream>
using namespace std;
class MagacinLL
{
public:
	Cvor* vrh;

	MagacinLL();
	void push(int);
	int pop();
	int  getVrh() { return vrh->info; }
	void stampaj();
};