#include "PolynomLL.h"
#include <iostream>
using namespace std;

void main()
{
	CPolynomLL list;
	CPolynomLL p1;
	CPolynomLL p2;
	p1.AddCoeftoList(0, 2);
	p1.AddCoeftoList(1, 3);
	p1.AddCoeftoList(5, 4);
	p2.AddCoeftoList(0, 2);
	p2.AddCoeftoList(1, 3);
	p2.AddCoeftoList(4, 4);
	p1.printlist();
	p2.printlist();
	list.Add(p1, p2);
	list.printlist();

	/*
	list.AddCoeftoList(0, 5);
	list.AddCoeftoList(1, 3);
	list.AddCoeftoList(2, 7);
	list.AddCoeftoList(3, 15);
	list.printlist;
	*/
}