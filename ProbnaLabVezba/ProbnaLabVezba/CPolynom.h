#include <iostream>
using namespace std;

class CPolynom
{
private:
	double* niz;
	int red_polinoma;
public:
	CPolynom();
	CPolynom(int order);
	~CPolynom();

	CPolynom* nadjiVecired(CPolynom& poly1, CPolynom& poly2);


	void Coef(int exp, double coef);
	CPolynom* Add(CPolynom* poly1, CPolynom * poly2);
	CPolynom* Mul(CPolynom * poly1, CPolynom * poly2);
	void Print();
};

