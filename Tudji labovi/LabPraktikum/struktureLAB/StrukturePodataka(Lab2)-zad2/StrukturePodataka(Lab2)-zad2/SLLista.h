#pragma once
#include"Node.h"
#include <iostream>

class SLList
{
public:
	Node* head;
	Node* tail;
public:
	SLList(){ head = tail = NULL; };
	~SLList()
	{
		if (!IsEmpty()) DeleteFromHead();
	};

	void DeleteFromHead()
	{
		Node* tmp;
		tmp = head;
		head = head->next;
		delete tmp;
	};


	void AddToHead(HashObject node)
	{
		{
			if (!IsEmpty())
			{
				Node* newNode = new Node(node, head);
				newNode->next = head;
				head = newNode;
			}
			else head = new Node(node);
		};
	}

	void DeleteEl(HashObject node)
	{
		if (!IsEmpty())
		{
			if (head->info == node)
			{
				Node* tmp;
				tmp = head;
				head = head->next;
				delete tmp;
			}
			else
			{
				Node* prev, *tmp;
				for (prev = head, tmp = head->next; tmp != NULL && !(tmp->info == node); prev = tmp, tmp = tmp->next);
				prev->next = tmp->next;
				delete tmp;
			}
		}
	}

	bool IsEmpty()
	{
		return head == NULL;
	};


	void Print()
	{
		Node* tmp;
		for (tmp = head; tmp != NULL; tmp = tmp->next)
		{
			tmp->Print();
		}
	}

};