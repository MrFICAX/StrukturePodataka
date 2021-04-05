#include "SDList.h"
#include<iostream>
using namespace std;

SDList::SDList()
{
	max = 0;
   tail = 0;
   head = -1;
   lrmp = -1;
   polje = NULL;
}
SDList::SDList(int x)
{
	max = x;
	 tail = 0;
	 head = -1;
	 lrmp = 0;
	 polje = new Cvor[max + 1];
	 int i;
	 for (i = 0; i<max; i++) 
	 {
		 polje[i].next = i + 1;
	 }
	 polje[max].next = -1;

}
SDList::~SDList()
{
	if (polje != NULL)
		delete[] polje;
}
void SDList::AddToHead(int el)
{
	{
		if (lrmp == -1) {
			return;
		}
		int tmp = lrmp;
		lrmp = polje[lrmp].next;
		polje[tmp].info = el;
		polje[tmp].prev = -1;
		polje[tmp].next = head;
		if (head == -1)
		{
			tail = head = tmp;
		}
		else
		{
			polje[head].prev = tmp;
			head = tmp;
		}
	}
}
void SDList::Remove(int el)
{
		int p;
		for (p =head; p != -1 && polje[p].info != el;p = polje[p].next);
			if (p != -1)
			{
				if (p == head)
					head = polje[head].next;
				else
					polje[polje[p].prev].next = polje[p].next;
				if (p == tail)
					tail = polje[tail].prev;
				else
				polje[polje[p].next].prev = polje[p].prev;
				polje[p].prev = -1;
				polje[p].next = lrmp;
				lrmp = p;
			}
	}
void SDList::Print()
{


	//for (int tmp = tail; tmp != -1; tmp = polje[tmp].prev)
	//{
		//polje[tmp].print();
		//cout << endl;
	//}
	for (int tmp = head; tmp != -1; tmp = polje[tmp].next)
	{
		polje[tmp].print();
		cout << endl;
	}
	//}
}


