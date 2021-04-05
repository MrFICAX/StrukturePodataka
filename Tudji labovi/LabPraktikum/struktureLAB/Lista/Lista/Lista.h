#pragma once
#include "Node.h"

class List
{
private:
	Node* head;
	Node* tail;
public:
	List();
	~List();
	bool isEmpty();
	bool isinList(int el);
	void AddToHead(int el);
	void AddToTail(int el);
	int DeleteFromHead();
	int DeleteFromTail();
	void DeleteEl(int el);
	void DeleteAll();
	//Node* FindNodePtr(int el);
	Node* GetHead();
	Node* GetNext(Node* n);
	int GetHeadEl();
	int GetNextEl(int el);
	void PrintAll();
	//void Sort(); 
};