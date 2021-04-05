#pragma once
#include<iostream>
using namespace std;
class Magacin 
{
	protected:
		int* niz;
		int velicina;
		int top;
public:
	Magacin();
	Magacin(int);
	~Magacin();

	int getTop();
	void push(int);
	int pop();
	bool isEmpty() { return top == -1; }
	int brojElemenata() { return (top + 1); }
	void stampam();

	int prioritet(char);
	void uPostfix(char*);

	double calcPrefix(char* inStr);//2015, redovni
	char* AddLong(char*, char*);//2014,redovni
};