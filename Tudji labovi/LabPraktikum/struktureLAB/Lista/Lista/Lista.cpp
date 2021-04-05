#include <iostream>
#include "Lista.h"
#include "Node.h"

using namespace std;

List::List() : head(0), tail(0)
{
}

List::~List()
{
	while (!isEmpty())
		int tmp = DeleteFromHead();

	/* Node* tmp = head;
	while(tmp!=tail)
	{
	Node* tmp1 = tmp;
	tmp=tmp->link;
	delete tmp1;
	}
	head=tail=0;
	*/
}

bool List::isEmpty()
{
	if (head == 0)
		return true;
	else
		return false;
}

bool List::isinList(int el)
{
	if (isEmpty())
		cout << "Lista je prazna!";
	else
	{
		Node* tmp = head;
		while (tmp->info != el && tmp != tail)
		{
			tmp = tmp->link;
			if (tmp == tail)
				return false;
			else
				return true;
		}
	}
}

void List::AddToHead(int el)
{
	head = new Node(el, head);
	if (tail == NULL)
		tail = head;
}

void List::AddToTail(int el)
{
	if (!isEmpty())
	{
		tail->link = new Node(el);
		tail = tail->link;
	}
	else
		head = tail = new Node(el);
}

int List::DeleteFromHead()
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

int List::DeleteFromTail()
{
	if (isEmpty())
		cout << "Lista je prazna!" << endl;
	int el = tail->info;
	Node* Del = tail;
	if (head == tail)
		head = tail = NULL;
	else
	{
		Node* tmp;
		for (tmp = head; tmp->link != tail; tmp = tmp->link)
		{
			tail = tmp;
			tail->link = NULL;
		}
	}
	delete Del;
	return el;
}

void List::DeleteEl(int el)
{
	if (isEmpty())
		cout << "Lista je prazna!" << endl;
	if (head == tail && head->info == el)
	{
		delete head;
		head = tail = NULL;
	}
	else if (el == head->info)
	{
		Node* tmp = head;
		head = head->link;
		delete tmp;
	}
	else
	{
		Node *pred, *tmp;
		for (pred = head, tmp = head->link; tmp != NULL && !(tmp->info == el); pred = pred->link, tmp = tmp->link)
			if (tmp != NULL)
			{
				pred->link = tmp->link;
				if (tmp == tail)
					tail = pred;
				delete tmp;
			}
	}
}

void List::DeleteAll()
{
	if (isEmpty())
		cout << "Lista je prazna!" << endl;
	Node* tmp = head;
	while (tmp != tail)
	{
		Node* tmp1 = tmp;
		tmp = tmp->link;
		delete tmp1;
	}
	head = tail = NULL;
}

Node* List::GetHead()
{
	if (isEmpty())
	{
		Node* tmp = NULL;
		return tmp;
	}
	return head;
}

Node* List::GetNext(Node* n)
{
	return n->link;
}

int List::GetHeadEl()
{
	if (isEmpty())
		return 0;
	return head->info;
}

void List::PrintAll()
{
	cout << "Izgled liste: ";
	for (Node* tmp = head; tmp != tail->link; tmp = tmp->link)
		cout << tmp->print() << " ";
	cout << endl;
}
