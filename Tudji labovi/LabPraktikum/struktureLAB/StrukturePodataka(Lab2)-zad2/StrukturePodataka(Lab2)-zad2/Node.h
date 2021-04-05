#pragma once
#include"HashObject.h"

class Node
{
public:
	HashObject info;
	Node *next;
public:
	Node(HashObject i, Node *p)
	{
		info = i;
		next = p;
	}

	Node(HashObject i)
	{
		info = i;
		next = NULL;
	}

	HashObject GetInfo()
	{
		return info;
	}

	void Print()
	{
		info.Print();
		cout << "->";
	}
};