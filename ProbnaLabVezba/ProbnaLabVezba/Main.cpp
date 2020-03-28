#include "CPolynom.h"
#include <iostream>
using namespace std;

void main() {

	CPolynom* temp = new CPolynom(4);
	temp->Coef(0,1);
	temp->Coef(1,2);
	temp->Coef(2,3);
	temp->Coef(3,4);
	temp->Print();

	CPolynom* temp2 = new CPolynom(5);
	temp2->Coef(0, 1);
	temp2->Coef(1, 2);
	temp2->Coef(2, 3);
	temp2->Coef(3, 4);
	temp2->Coef(4, 5);
	temp2->Print();

	CPolynom* temp3 = new CPolynom(5);
	
	temp3 = temp3->Add(temp,temp2);
	temp3->Print();
	temp3 = temp3->Mul(temp, temp2);
	temp3->Print();

	temp->~CPolynom();
}