#pragma once
#include "HashObject.h"
#include "Node.h"

template< class T >
class SLList
{
public:
	Node<T>* head;
	Node<T> * tail;
public:
	SLList(){ head = NULL; };
	~SLList();

	T deleteFromHead();
	void addToHead(T node);
	void deleteEl(T node);
	bool isEmpty(){ return head == NULL; };
	void print();
};

template<class T>
SLList<T>::~SLList()
{
	if (!isEmpty()) deleteFromHead();
};

template< class T>
T SLList<T>::deleteFromHead()
{
	T el = head->info;
	Node<T>* tmp;
	tmp = head;
	if (head == tail)
		head = tail = NULL;
	else
	head = head->next;
	delete tmp;
	return el;
};

template< class T >
void SLList<T>::addToHead(T el)
{
	head = new Node<T>(el);
	if (tail == NULL)
		tail = head;
		
};


template< class T >
void SLList<T>::deleteEl(T node)
{
	if (!isEmpty())
	{
		if (head->info == node)
		{
			Node<T>* tmp;
			tmp = head;
			head = head->next;
			delete tmp;
		}
		else
		{
			Node<T>* prev, *tmp;
			for (prev = head, tmp = head->next; tmp != NULL && !(tmp->info == node); prev = tmp, tmp = tmp->next);
			prev->next = tmp->next;
			delete tmp;
		}
	}

};

template < class T >
void SLList<T>::print()
{
	Node<T>* tmp;
	for (tmp = head; tmp != NULL; tmp = tmp->next)
		cout << tmp->printNode() << "";
};
