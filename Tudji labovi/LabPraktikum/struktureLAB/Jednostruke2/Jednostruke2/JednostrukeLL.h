#include <iostream>
#include "Cvor.h"
using namespace std;
#pragma once
template<class T>
class SLList
{
protected:
	SLLNode<T> * tail, *head;
public:
	SLList()
	{
		head = tail = NULL;

	}
	~SLList();
	bool isEmpty(){
		return head == NULL;
	}
	void addToHead(T el);
	void addToTail(T el);
	T deleteFromHead();
	T deleteFromTail();
	SLLNode<T> * findNodeptr(T el);
	SLLNode<T> * getHead(){ return head; }
	SLLNode<T> * getNext(SLLNODE<T> * ptr);
	T getHeadEl();
	T getNextEl(T el);
	void printAll();
	bool isInList(T el);
	void deleteEl(T el);

};
template<class T>
void SLList<T>::addToHead(T el)
{
	head = new SLLNode<T>(el, head);
	if (tail == NULL)
		tail = head;
}
template<class T>
void SLList<T>::addToTail(T el)
{
	if (!isEmpty())
	{
		tail->next = new SLLNode<T>(el)
			tail = tail->next;
	}
	else
		head = tail = new SLLNode<T>(el);
}
template<class T>
T SLList<T>::deleteFromHead()
{
	if (isEmpty())
		throw new SBPException("Lista je prazna!");
		T el = head->info;
		SLLNode<T>* tmp = head;
		if (head == tail)
			head = tail = NULL;
		else
			head = head->next;
		delete tmp;
		return el;

}
template<class T>
T SLList<T>::deleteFromTail()
{
	if (isEmpty())
		throw new SBPException("Lista je prazna!");
	T el = tail->info;
	SLLNode<T>* forDel= tail;
	if (head == tail)
		head = tail = NULL;
	else
	{
		SLLNode<T> * tmp;
		for (tmp = head; tmp->next != tail; tmp = tmp->next)
			tail = tmp;
		tail->next = NULL;
	}
	delete forDel;
	return el;
}
template<class T>
