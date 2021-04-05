#pragma once
#include "Edge.h"
#include "Node.h"
#include <queue>
class GraphAsLists{

protected:
	Node *start;
	long nodeNum;

public:
	GraphAsLists();
	~GraphAsLists() { }
	void insertNode(int a);
	bool insertEdge(int a, int b);
	void print();
	Node* findNode(int a);
	Edge* findEdge(int a, int b);
	void Obilazak(int a);
	Node* maxUlaz();
	void UOrjentisani();
	int Disjunktni();
	bool status1();
	int indeks();
	


};

GraphAsLists::GraphAsLists()
{
	start = NULL;
	this->nodeNum = 0;
}

void GraphAsLists::insertNode(int a)
{

	Node *novi = new Node(a, NULL, start, 0);
	start = novi;
	nodeNum++;
}

bool GraphAsLists::insertEdge(int a, int b)
{
	Node *pa = findNode(a);
	Node *pb = findNode(b);
	if (pa == NULL || pb == NULL) return true;
	Edge *e = new Edge(pb, pa->adj);
	if (e == NULL) return false;
	pa->adj = e;
	return true;
	void uOrjentisani();
}


Node* GraphAsLists::findNode(int a)
{
	Node *ptr = start;
	while (ptr != NULL && ptr->info != a)
		ptr = ptr->next;
	return ptr;
}

Edge* GraphAsLists::findEdge(int a, int b)
{
	Node *pa = findNode(a);
	Node *pb = findNode(b);
	if (pa == NULL || pb == NULL) return NULL;
	Edge *ptr = pa->adj;
	while (ptr != NULL && ptr->dest != pb)
		ptr = ptr->link;
	return ptr;

}

void GraphAsLists::print()
{
	Node *ptr = start;
	while (ptr != NULL)
	{
		cout << ptr->info << "->";
		Edge *pa = ptr->adj;
		while (pa != NULL)
		{
			cout << pa->dest->info << "|";
			pa = pa->link;
		}
		cout << "\r\n";
		ptr = ptr->next;

	}
}
void GraphAsLists::Obilazak(int a)
{
	Node*ptr = start;
	queue<Node*> red;
	while (ptr != NULL)
	{
		ptr->status = 1;
		ptr = ptr->next;
	}
	ptr = findNode(a);
	if (ptr == NULL) return;
	ptr->status = 2;
	red.push(ptr);
	while (!red.empty())
	{
		ptr = red.front();
		red.pop();
		ptr->status = 3;
		ptr->visit();
		Edge *pot = ptr->adj;
		while (pot != NULL)
		{
			if (pot->dest->status == 1)
			{
				pot->dest->status = 2;
				red.push(pot->dest);
			}
			pot = pot->link;
		}
	}
}
void GraphAsLists::UOrjentisani()
{
	for (Node * pom1 = start; pom1 != NULL; pom1 = pom1->next)
		for (Node* pom2 = pom1->next; pom2 != NULL; pom2 = pom2->next)
			if (findEdge(pom1->info, pom2->info) && !findEdge(pom2->info, pom1->info))
				insertEdge(pom2->info, pom1->info);
}
bool GraphAsLists::status1()
{
	for (Node * n = start; n != NULL; n = n->next)
		if (n->info == 1)
			return true;
		else return false;

}
int GraphAsLists::indeks()
{
	
}
int GraphAsLists::Disjunktni()
{
	int brojac = 0;
	for (Node * n = start; n != NULL; n = n->next)
		if (n->status == 1)
		{Obilazak(p->info);
		brojac++;
	}
	return brojac;
}

};