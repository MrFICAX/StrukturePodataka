#pragma once
#include <iostream>
using namespace std;

class SDNode
{
public:
	int info;
	int prev;
	int next;
	SDNode() { prev = 0; next = 0; info = 0; };
	SDNode(int i) { info = i; prev = 0; next = 0; };
	SDNode(int i, int p, int n) 
	{
		info = i;
		prev = p; 
		next = n;
	};
	~SDNode() { };
	void print() 
	{ cout<<prev<<" "; 
	cout << info << " ";
	cout << next << " ";
	};
	bool isEqual(int el) { return el == info; };
};