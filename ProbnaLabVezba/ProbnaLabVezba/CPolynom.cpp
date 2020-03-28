#include "CPolynom.h"
#include <iostream>
using namespace std;

CPolynom::CPolynom(){}

CPolynom::CPolynom(int order) {
	red_polinoma = order;
	niz = new double[red_polinoma];
	for (int i = 0; i < red_polinoma; i++)
			niz[i] = 0;
}
CPolynom::~CPolynom() {
	delete[] niz;
}
	CPolynom* CPolynom::nadjiVecired(CPolynom & poly1, CPolynom & poly2) {
		if (poly1.red_polinoma < poly2.red_polinoma)
			return &poly2;
		else
			return &poly1;

}
void CPolynom::Coef(int exp, double coef) {
	niz[exp] = coef;
}
CPolynom* CPolynom::Add(CPolynom* poly1, CPolynom* poly2) {
	int max = 0;
	if (poly1->red_polinoma < poly2->red_polinoma)
		max = poly1->red_polinoma;
	else 
		max = poly2->red_polinoma;
	int razlika = 1;
	if (poly1->red_polinoma < poly2->red_polinoma)
		razlika = poly2->red_polinoma - max;
	else
		razlika = poly1->red_polinoma - max;
	
	CPolynom privremeno;
	CPolynom * niz2 = new CPolynom(privremeno.nadjiVecired(*poly1,*poly2)->red_polinoma+1);
	int temp = 0;

	while(temp <= max)
	{
		niz2->niz[temp] = poly1->niz[temp] + poly2->niz[temp];
		temp++;
	}
	while (razlika != 0)
	{
	
		niz2->niz[temp] = privremeno.nadjiVecired(*poly1, *poly2)->niz[temp];
		razlika--;
	}
	return niz2;
}
CPolynom* CPolynom::Mul(CPolynom* poly1, CPolynom* poly2) {
	int max = 0;
	if (poly1->red_polinoma < poly2->red_polinoma)
		max = poly1->red_polinoma;
	else
		max = poly2->red_polinoma;
	int razlika = 1;
	if (poly1->red_polinoma < poly2->red_polinoma)
		razlika = poly2->red_polinoma - max;
	else
		razlika = poly1->red_polinoma - max;
	CPolynom privremeno;
	CPolynom* niz2 = new CPolynom(privremeno.nadjiVecired(*poly1, *poly2)->red_polinoma + 1);
	int temp = 0;
	
	while (temp <= max)
	{
		niz2->niz[temp] = poly1->niz[temp] * poly2->niz[temp];
		temp++;
	}
	while (razlika != 0)
	{
		niz2->niz[temp] = privremeno.nadjiVecired(*poly1, *poly2)->niz[temp];
		razlika--;
	}
	return niz2;
}
void CPolynom::Print() {
	red_polinoma -= 1;
		for (int i = this->red_polinoma; i >= 0; i--)
		{
			if (i != 0)
			{
				cout << niz[i] << "X^" << i;
				cout << "+";
			}
			else
			{
				cout << niz[i] << endl;
			}
		}
}