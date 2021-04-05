#include <iostream>
#include "SortList.h"
using namespace std;
CSortList::CSortList()
{
	head = 0;
	tail = 0;
}
CSortList::~CSortList()
{
	while (!isEmpty())
		int tmp = DeleteFromHead();
}
bool CSortList::isEmpty()
{
	if (head == 0)
		return true;
	else
		return false;
}
void CSortList::AddToHead(int el)
{
	head = new Node(el, head);
	if (tail == NULL)
		tail = head;
}
int CSortList::DeleteFromHead()
{
	if (isEmpty())
		cout << "Lista je prazna!" << endl;
	else
	{
		int el = head->info;
		Node* tmp = head;
		if (head == tail)
			head = tail = NULL;
		else
			head = head->link;
		delete tmp;
		return el;
	}
}
void CSortList::Sort()

{
	Node* ptr1;
	Node* ptr2, *prev2;
	for (ptr1 = tail; ptr1 != head; ptr1 = prev2)
	{
		prev2 = NULL;
		for (ptr2 = head; ptr2->link != ptr1;)
		{
			if (ptr2->info > ptr2->link->info)
			{
				SwapNeighbors(ptr2, prev2);
				if (prev2 != NULL)
				
					prev2 = prev2->link;
				else
					prev2 = head;
			}
			else {
				prev2 = ptr2;
				ptr2 = ptr2->link;
			}
		}
		if (ptr2->info > ptr2->link->info)
		{
			SwapNeighbors(ptr2, prev2);
			if (prev2 != NULL)
			{
				prev2 = prev2->link;
			}
			else {
				prev2 = head;
			}
		}
		else {
			prev2 = ptr2;
		}
	}
} 
void CSortList::Sort2()
{
		Node *ptr, *prev;
		Node *ptr1, *prev1, *ptr2, *prev2;
		prev1 = NULL;
		for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->link) {
			ptr = ptr1;
			prev = prev1;
			prev2 = ptr1;
			for (ptr2 = ptr1->link; ptr2 != NULL; ptr2 = ptr2->link) {
				if (ptr->info > ptr2->info) {
					ptr = ptr2;
					prev = prev2;
				}
				prev2 = ptr2;
			}
			if (ptr1 != ptr) {
				Swap(ptr1, prev1, ptr, prev);
				ptr1 = ptr;
			}
			prev1 = ptr1;
		}
	}
void CSortList::Sort3()
{
	
		Node *ptr1, *prev1, *ptr2, *prev2;
		prev1 = head;
		for (ptr1 = head->link; ptr1 != NULL;) {
			prev2 = NULL;
			ptr2 = head;
			while (ptr2 != ptr1 && ptr1->info<ptr2->info) {
				prev2 = ptr2;
				ptr2 = ptr2->link;
			}
			if (ptr1 != ptr2) {
				if (prev2 != NULL) {
					prev1->link = ptr1->link;
					prev2->link = ptr1;
					ptr1->link = ptr2;
				}
				else {
					prev1->link = ptr1->link;
					head = ptr1;
					ptr1->link = ptr2;
				}
				ptr1 = prev1->link;
			}
			else {
				prev1 = ptr1;
				ptr1 = ptr1->link;
			}
		}
	}


void CSortList::PrintAll()
{
	cout << "Izgled liste: ";
	for (Node* tmp = head; tmp !=NULL; tmp = tmp->link)
		cout << tmp->print() << " ";
	cout << endl;
}
void CSortList::SwapNeighbors(Node * ptr, Node* prev)
{
	if (prev == NULL)
	{
		head = ptr->link;
		ptr->link = ptr->link->link;
		head->link = ptr;
	}
	else
	{
		prev->link = ptr->link;
		ptr->link = ptr->link->link;
		prev->link->link = ptr;
	}
}
void  CSortList::Swap(Node* ptr1, Node* prev1, Node*ptr2, Node* prev2)
{
	if (ptr1 == ptr2) {
		return;
	}
	else if (ptr1->link == ptr2) {
		SwapNeighbors(ptr1, prev1);
	}
	else if (ptr2->link== ptr1) {
		SwapNeighbors(ptr2, prev2);
	}
	else {
		if (prev1 == NULL)
			head = ptr2;
		else
			prev1->link = ptr2;
		if (prev2 == NULL)
			head = ptr1;
		else
			prev2->link = ptr1;
		Node* tmp = ptr1->link;
		ptr1->link = ptr2->link;
		ptr2->link = tmp;
	}

}
void  CSortList::InsertInSorted(Node* ptr)
	{
		Node *ptr1, *prev1;
		prev1 = NULL;
		ptr1 = head;
		while (ptr1 != NULL && ptr->info<ptr1->info) {
			prev1 = ptr1;
			ptr1 = ptr1->link;
		}
		if (prev1 != NULL)
		{
			prev1->link = ptr;
			ptr->link = ptr1;
		}
		else
		{
			head = ptr;
			ptr->link = ptr1;
		}
	}

