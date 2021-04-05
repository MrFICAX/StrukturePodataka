#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

class CPolynomLL
{
protected:
	Node *head, *tail;
public:
	CPolynomLL(){ head = NULL; tail = NULL; }
	~CPolynomLL();
	bool isempty()
	{
		return (head == NULL);
	}
	void AddCoeftoList(int exp, double coef);
	CPolynomLL* Add(CPolynomLL& l1, CPolynomLL& l2);
	CPolynomLL * Mull(CPolynomLL & l1, CPolynomLL & l2);
	void printlist();
	Node* getHead()
	{
		return head;
	}
	void deletefromHead()
	{
		Node* tmp = head;
		if (head == tail)
		{
			head = tail = NULL;
		}
		else
		{
			head = head->link;
		}
		delete tmp;
	}
};