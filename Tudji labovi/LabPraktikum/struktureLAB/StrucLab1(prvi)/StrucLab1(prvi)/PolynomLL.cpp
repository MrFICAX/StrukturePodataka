#include "PolynomLL.h"

void CPolynomLL::AddCoeftoList(int exp, double coef)
{
	if (!this->isempty())
	{

		tail->link = new Node(exp, coef);
		tail = tail->getnext();

	}
	else
	{
		head = tail = new Node(exp, coef);
	}
}

void CPolynomLL::printlist()
{
	for (Node* tmp = head; tmp != NULL; tmp = tmp->getnext())
	{
		tmp->print();
		cout << " + ";
	}
	cout << endl;
}
CPolynomLL::~CPolynomLL()
{
	while (!isempty())
	{
		this->deletefromHead();
	}
}

CPolynomLL* CPolynomLL::Add(CPolynomLL& p1, CPolynomLL& p2)
{
	Node *tmp1, *tmp2;
	while (!this->isempty())
	{
		this->deletefromHead(); // praznimo listu za rezultat;
	}


	for (tmp1 = p1.getHead(); tmp1 != NULL; tmp1 = tmp1->getnext())
		this->AddCoeftoList(tmp1->rexp(), tmp1->rcoef());
	for (tmp2 = p2.getHead(); tmp2 != NULL; tmp2 = tmp2->getnext())
		for (tmp1 = this->getHead(); tmp1 != NULL; tmp1 = tmp1->getnext())
		{
			if (tmp1->rexp() == tmp2->rexp())
			{
				tmp1->coef += tmp2->coef;
			}
			else if (tmp1->link == NULL)
			{
				this->AddCoeftoList(tmp2->rexp(), tmp2->rcoef());
			}
		}
	return (this);
}
CPolynomLL* CPolynomLL::Mull(CPolynomLL & l1, CPolynomLL & l2)
{
	Node *tmp1, *tmp2;
	while (!this->isempty())
	{
		this->deletefromHead(); // praznimo listu za rezultat;
	}
	for (tmp1 = l1.getHead(); tmp1 != NULL; tmp1 = tmp1->getnext())
		this->AddCoeftoList(tmp1->rexp(), tmp1->rcoef());
	for (tmp2 = l2.getHead(); tmp2 != NULL; tmp2 = tmp2->getnext())
		for (tmp1 = this->getHead(); tmp1 != NULL; tmp1 = tmp1->getnext())
		{
			tmp1->coef = tmp1->coef*tmp2->coef;
			tmp1->exp = tmp1->exp + tmp1->exp;
		}

}