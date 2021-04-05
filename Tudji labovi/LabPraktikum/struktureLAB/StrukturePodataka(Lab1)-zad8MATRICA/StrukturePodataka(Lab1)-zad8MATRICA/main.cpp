#include <iostream>
using namespace std;
#include "Node.h"
#include "Matrica.h"

void main()
{
	Matrica mat(5);
	mat.SetAt(1, 3, 25);
	mat.Print();
	mat.SetAt(4, 3, 33);
	mat.SetAt(3, 4, 55);
	mat.Print();
}