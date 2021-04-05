#include"RedLL.h"

RedLL::RedLL() { head = tail = NULL; }
void RedLL::enqueue(int el)
{
	if (!isEmpty())
	{
		tail->setNext(new Cvor(el, NULL));
		tail = tail->getNext();
	}
	else
		head = tail = new Cvor(el, NULL);
}
int RedLL::dequeue()
{
	if (head == NULL)
		throw "Lista je prazna.";
	int rez = head->info;
	Cvor* tmp = head;
	if (head == tail)
		head = tail = NULL;
	head = head->getNext();
	delete tmp;
	return rez;
}
void RedLL::stampaj()
{
	for (Cvor* tmp = head;tmp != NULL;tmp=tmp->getNext())
		cout << tmp->getInfo() << " ";
	cout << endl;
}