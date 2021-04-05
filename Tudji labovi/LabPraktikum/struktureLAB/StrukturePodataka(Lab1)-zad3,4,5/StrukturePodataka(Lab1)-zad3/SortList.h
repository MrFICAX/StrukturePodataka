#include <iostream>
#pragma once
using namespace std;
#include "Node.h"
class CSortList
{
private:
	Node* head;
	Node* tail;
public:
	CSortList();
	~CSortList();
	void AddToHead( int el);
	void Sort();
	void Sort2();
	void Sort3();
	bool isEmpty();
	int DeleteFromHead();
	void PrintAll();
	void SwapNeighbors(Node * ptr, Node * prev);
	void Swap(Node* ptr1, Node* prev1, Node*ptr2, Node* prev2);
	void InsertInSorted(Node * ptr);

};