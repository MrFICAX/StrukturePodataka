#pragma once
#include<iostream>
using namespace std;
class Quick {
	public:
	int *niz;
	int brElem;
public:
	Quick();
	Quick(int n);
	~Quick();
	void quickSort(int *niz, int brElemPrim);
	void quickSort(int *niz, int first, int last);
	void swap(int first, int upper);
	friend istream& operator >> (istream& in, Quick& q);
	friend ostream& operator<<  (ostream& out, const Quick& q);


};