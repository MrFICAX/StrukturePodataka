#include <iostream>
#pragma once 
using namespace std;
class Cvor {
public:
	int info;
	int prev;
	int next;
public:
	Cvor(){};
	Cvor(int x)
	{
		info = x;
	}
	~Cvor(){};
	void print() 
	{
		cout<<prev<<" ";
		cout << info<<" " ;
		cout << next <<" ";

	}


};