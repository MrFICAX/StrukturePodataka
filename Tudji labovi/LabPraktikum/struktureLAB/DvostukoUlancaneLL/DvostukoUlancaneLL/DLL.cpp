#include "DLL.h"


DLLista::DLLista()
{
	head = tail = NULL;
}
bool DLLista::isEmpty()
{
	return head == NULL;
}
void DLLista::addToHead(int a)
{
	if (!isEmpty())
	{
		head = new Node(a, head, NULL);
		head->next->prev = head;
	}
	else
		head = tail = new Node(a);
}
void DLLista::Print()
{
	for (Node* tmp = head; tmp != NULL; tmp = tmp->next)
		cout << tmp->info << " ";
	cout << endl;
}
void DLLista::BubbleDvostruke()
{
	int j;
	Node* pom2;
	Node* pom3 = NULL;
	int pomocni = 0;
	int pomocni1 = 0;
	int brel = 0;
	Node* pom4;
	for (pom4 = head; pom4 != NULL; pom4 = pom4->next)
		brel++;
	for (int i = 0; i < brel - 1; i++)
		for (pom2 = head, j = brel - 1; j > i; j--, pom2 = pom2->next)
			if (pom2->info > (pom2->next)->info)
			{
				pomocni = pom2->info;
				pom2->info = (pom2->next)->info;
				(pom2->next)->info = pomocni;
			}
}
void DLLista::deleteFromTail()
{
	Node*tmp = tail;
	if (head == tail)
	{
		head = tail = NULL;
	}
	else
	{
		tail = tail->prev;
		tail->next = NULL;
	}
	delete tmp;
}

void DLLista::addToTail(int a)
{
	if (!isEmpty())
	{
		tail = new Node(a, NULL, tail);
		(tail->prev)->next = tail;
	}
	else
		head = tail = new Node(a);
}
void DLLista::deleteFromHead()
{
	Node* tmp = head;
	if (head == tail)
		head = tail = NULL;
	else
	{
		head = head->next;
		head->prev = NULL;
	}
	delete tmp;
}
DLLista::~DLLista()
{
	while (!isEmpty())
		deleteFromHead();
}