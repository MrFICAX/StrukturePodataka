#include"Quick.h"
#include<iostream>
using namespace std;
void main() {
	int n = 5;
	Quick niz1(5);
	cin >> niz1;
	cout << niz1;
	niz1.quickSort(niz1.niz, n);
	cout << niz1;
}