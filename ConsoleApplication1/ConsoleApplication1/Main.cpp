#include "Test.h"
#include <iostream>
using namespace std;

void  main() {
	Test* t = new Test();
	t->Funkcija();
	cout << t->returnSquare(5) << endl;
	delete t;
}