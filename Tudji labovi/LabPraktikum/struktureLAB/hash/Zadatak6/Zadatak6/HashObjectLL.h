#pragma once
#include "HashObject.h"


class HashObjectLL
{
private:

	HashObject* head;
	HashObject* tail;

public:

	HashObjectLL()
	{
		head = tail = NULL;
	}

	~HashObjectLL()
	{
		while (!isEmpty())
			deleteFromHead(); 
	}

	void addToHead(char* a, char* b, int c)
	{
		head = new HashObject(a, b, c,head);
		if (tail == NULL)
			tail = head;
	}

	void deleteFromHead()
	{
		HashObject* tmp = head;

		if (head == tail)
			head = tail = NULL;
		else
			head = head->next;
		delete tmp;
	}

	void deleteFromTail()
	{
		HashObject* tmp = tail;
		if (head == tail)
			head = tail = NULL;
		else
		{
			HashObject* pom;
			for (pom = head; pom != tail; pom = pom->next);
			tail = pom;
			tail->next = NULL; 
		}
		delete tmp;
	}

	bool isEmpty()
	{
		return head == NULL;
	}

	void print()
	{
		for (HashObject*tmp = head; tmp; tmp = tmp->next)
			tmp->print();
		cout << endl;
	}
	
	bool isEqual1(char* a, char* b)
	{
		for (HashObject* tmp = head; tmp != NULL; tmp = tmp->next)
		if (tmp->isEqual(a, b))
			return true;
		return false;
	}

	HashObject* find(char* s, char* d)
	{
		for (HashObject* tmp = head; tmp != NULL; tmp = tmp->next)
		if (tmp->isEqual(s, d))
			return tmp;
		return NULL;
	}

	bool deleteEl(char*a, char* b)
	{
		if (!isEmpty())
		{
			if (head->isEqual(a, b))
			{
				deleteFromHead();
				return true;
			}
			else
			{
				if (tail->isEqual(a, b))
				{
					deleteFromTail();
					return true;
				}
				else
				{
					HashObject* tmp, *prev;
					for (tmp = head->next, prev = head; tmp->next != tail; tmp = tmp->next, prev = prev->next)
					if (tmp->isEqual(a, b))
					{
						prev->next = tmp->next;
						return true;
					}
				}
			}
		}
		else
		{
			return false;
		}
	}
};