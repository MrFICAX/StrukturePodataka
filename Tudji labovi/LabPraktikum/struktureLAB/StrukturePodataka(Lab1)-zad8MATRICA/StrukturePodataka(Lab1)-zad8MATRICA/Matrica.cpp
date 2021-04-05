#include "Matrica.h"

Matrica::Matrica(int a)
{
	dim = a;
	brel = 0;
	vrste = new Node*[dim];
	kolone = new Node*[dim];
	for (int i = 0; i < dim; i++)
	{
		vrste[i] = NULL;
		kolone[i] = NULL;
	}
}
void Matrica::SetAt(int a, int b, int c)
{
	if (vrste[a] == NULL && kolone[b] == NULL)
	{
		vrste[a] = new Node(a, b, c, vrste[a], kolone[b]);
		kolone[b] = vrste[a];
	}
	else if (vrste[a] == NULL)
	{
		Node* pom;
		for (pom = kolone[b]; pom->linkk != NULL; pom = pom->linkk);
		pom->linkk = new Node(a, b, c, NULL, NULL);
		vrste[a] = pom->linkk;
	}
	else if (kolone[b] == NULL)
	{

		Node* pom;
		for (pom = vrste[a]; pom->linkv != NULL; pom = pom->linkv);
		pom->linkv = new Node(a, b, c, NULL, NULL);
		kolone[b] = pom->linkv;

	}
	else {
		Node *pom1;
		Node *pom2;
		for (pom1 = kolone[b]; pom1->linkk != NULL; pom1 = pom1->linkk);
		for (pom2 = vrste[a]; pom2->linkv != NULL; pom2 = pom2->linkv);
		pom1->linkk = new Node(a, b, c, NULL, NULL);
		pom2->linkv = pom1->linkk;
	}

}
Matrica::Matrica()
{
}


Matrica::~Matrica()
{
}
void Matrica::Print()
{
	int i;
	for (i = 0; i<dim; i++)
	{
		for (Node *pom = vrste[i]; pom != NULL; pom = pom->linkv)
			pom->print();
		cout << endl;
	}
}