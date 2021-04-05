#pragma once
#include"Cvor.h"
#include<iostream>
using namespace std;
class RedLL
{
public:
	Cvor* head, *tail;

	RedLL();
	void enqueue(int el);
	int dequeue();
	int getInfo() { return head->info; }
	void stampaj();
	bool isEmpty() { return head == NULL; }

};