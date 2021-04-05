#include "SDLLista.h"
#include <iostream>
using namespace std;
SDLList::SDLList()
{
	size = 0;
	head = 0;
	tail = 0;
	lrmp = 0;
	data = NULL;
}
SDLList::SDLList(int n)
{
	size = n;
	head = tail = 0;
	lrmp = 1;
	data = new SDNode[size + 1];
	int i;
	for (i = 1; i<size; i++)
	{
		data[i].next = i + 1;
	}
	data[size].next = 0;
}
SDLList::~SDLList()
{
	if (data != NULL)
	{
		delete[] data;
	}
}
void SDLList::printAll()
{

	for (int tmp = tail; tmp != 0; tmp = data[tmp].prev)
	{
		data[tmp].print();
		cout << endl;
	}
}
void SDLList::addToHead(int el) 
{
	if (lrmp == 0) {
		return;
	}
	int tmp = lrmp;
	lrmp = data[lrmp].next;
	data[tmp].info = el;
	data[tmp].prev = 0;
	data[tmp].next = head;
	if (head == 0) {
		tail = head = tmp;
	}
	else 
	{
		data[head].prev = tmp;
		head = tmp;
	}
}
void SDLList::deleteEl(int el)
{
	int tmp;
	for (tmp = head; tmp != 0 && data[tmp].info != el;tmp = data[tmp].next);
		if (tmp != 0)
		{
			if (tmp == head)
				head = data[head].next;
			else
				data[data[tmp].prev].next = data[tmp].next;
			if (tmp == tail)
				tail = data[tail].prev;
			else
				data[data[tmp].next].prev = data[tmp].prev;
			data[tmp].prev = 0;
			data[tmp].next = lrmp;
			lrmp = tmp;
		}
}