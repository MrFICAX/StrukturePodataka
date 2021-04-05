#include "Polinom.h"

void Polinom::Coef(int e, double c)
{
	Node*tmp = head;
	while (tmp->stepen != e)
		tmp = tmp->next;
	tmp->koeficijent = c;
}
Polinom::Polinom()
{
	max = -1;
	head = tail = NULL;
}
Polinom::Polinom(int m)
{
	max = m;
	head = tail = new Node(0, 0);
	for (int i = 1; i <= max; i++)
	{
		head = new Node(0, i, head);
	}
}
bool Polinom::isEmpty()
{
	return head == NULL;
}
Polinom::Polinom(const Polinom&pol)
{
	max = pol.max;
	head = tail = new Node(0, 0);
	for (int i = 1; i <= max; i++)
		head = new Node(0, i, head);
	Node*t1 = head;
	Node*t2 = pol.head;
	for (int i = 1; i <= max; i++)
	{
		t1->koeficijent = t2->koeficijent;
		t1->stepen = t2->stepen;
		t1 = t1->next;
		t2 = t2->next;
	}
	t1->koeficijent = t2->koeficijent;
	t1->stepen = t2->stepen;
}

Polinom::~Polinom()
{
	while (!isEmpty())
		DeleteHead();
}
void Polinom::DeleteHead()
{
	Node* tmp = head;
	if (head == tail)
		head = tail = NULL;
	else
		head = head->next;
	delete tmp;
}
void Polinom::Print()
{
	Node* tmp = head;
	int m = max;
	while (m >= 0)
	{
		if (m != max)
			cout << "+";
		cout << tmp->koeficijent << "x" << m--;
		tmp = tmp->next;
	}
	cout << endl;
}
Polinom* Polinom::Add(Polinom pol1, Polinom pol2)
{
	if (pol1.max >= pol2.max)
	{
		Node *t = this->head;
		Node* t1 = pol1.head;
		Node* t2 = pol2.head;
		while ((t1->stepen)>(t2->stepen))
		{
			t->koeficijent = t1->koeficijent;
			t1 = t1->next;
			t = t->next;
		}
		while (t1->stepen > 0)
		{
			t->koeficijent = t1->koeficijent + t2->koeficijent;
			t = t->next;
			t1 = t1->next;
			t2 = t2->next;
		}
		t->koeficijent = t1->koeficijent + t2->koeficijent;
		return this;
	}
	else
	{
		Node* t = this->head;
		Node* t1 = pol1.head;
		Node* t2 = pol2.head;
		while (t2->stepen>t1->stepen)
		{
			t->koeficijent = t2->koeficijent;
			t2 = t2->next;
			t = t->next;
		}
		while (t1->stepen > 0)
		{
			t->koeficijent = t1->koeficijent + t2->koeficijent;
			t = t->next;
			t1 = t1->next;
			t2 = t2->next;
		}
		t->koeficijent = t1->koeficijent + t2->koeficijent;
		return this;
	}
}
Polinom* Polinom::Multiply(Polinom pol1, Polinom pol2)
{
	Node* t = this->head;
	Node* t1 = pol1.head;
	Node* t2 = pol2.head;
	while (t1->stepen > 0)
	{
		t2 = pol2.head;
		while (t2->stepen > 0)
		{
			t = this->head;
			double pomkoef = 0;
			int pomstepen = 0;
			pomkoef = t1->koeficijent*t2->koeficijent;
			pomstepen = t1->stepen + t2->stepen;
			while (t->stepen != (t1->stepen + t2->stepen))
			{
				t = t->next;
			}
			this->Coef(pomstepen, (t->koeficijent + pomkoef));
			t2 = t2->next;

		}
		cout << t1->koeficijent << endl;
		t1 = t1->next;
	} // ovde i t1 i t2 su sada na odgovarajucim slobdnim clanovima
	cout << t1->koeficijent << endl;
	cout << t2->koeficijent << endl;
	t = this->head;
	while (t->stepen != t1->stepen)
	{
		t = t->next;
	}
	this->Coef(t->stepen, t1->koeficijent*t2->koeficijent);
	Node* pomocni1 = t1;
	Node* pomocni2 = t2;
	t1 = pol1.head;
	while (t1->stepen > 0)
	{
		t = this->head;
		while (t->stepen != (t1->stepen + t2->stepen))
		{
			t = t->next;
		}
		double pomkoef2 = 0;
		int pomstepen2 = 0;
		pomstepen2 = t1->stepen + t2->stepen;
		pomkoef2 = t1->koeficijent*t2->koeficijent;
		this->Coef(pomstepen2, (t->koeficijent + pomkoef2));
		t1 = t1->next;
	}
	t1 = pomocni1;
	t2 = pol2.head;
	while (t2->stepen > 0)
	{
		t = this->head;
		while (t->stepen != (t1->stepen + t2->stepen))
		{
			t = t->next;
		}
		int pomstepen3 = 0;
		double pomkoef3 = 0;
		pomstepen3 = t1->stepen + t2->stepen;
		pomkoef3 = t1->koeficijent*t2->koeficijent;
		this->Coef(pomstepen3, (t->koeficijent + pomkoef3));
		t2 = t2->next;
	}
	return this;
}