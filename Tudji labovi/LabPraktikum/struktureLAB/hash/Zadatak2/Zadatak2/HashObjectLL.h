#pragma once
#include "HashObject.h"



class HashObjectLL
{
private:

	HashObject* head, *tail;

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

	bool isEmpty()
	{
		return head == NULL;
	}

	void addToHead(char* ime, char* prezime, int brTelefona)
	{
		head = new HashObject(ime, prezime, brTelefona, head);
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

	HashObject* find(char* s,char* d)
	{
		for (HashObject* tmp = head; tmp != NULL; tmp = tmp->next)
		if (tmp->isEqual(s,d))
			return tmp;
		return NULL;
	}

	bool deleteEl(char* s,char* d)
	{
		if (head->isEqual(s,d))
		{
			deleteFromHead();
			return 1;
		}
		else
		{

			if (tail->isEqual(s,d))
			{
				deleteFromTail();
				return 1;
			}
			else
			{
				HashObject* tmp;
				HashObject* prev;
				for (tmp = head->next,prev=head; (tmp->next != tail && !(tmp->isEqual(s,d))); tmp = tmp->next,prev=prev->next);
				if (tmp->isEqual(s,d))
				{
					prev->next = tmp->next;
					delete tmp;
					return 1;
				}
			}
		}
		return 0;
	}

	void print()
	{
		for (HashObject*tmp = head; tmp; tmp = tmp->next)
			tmp->print();
		cout << endl;
	}


};