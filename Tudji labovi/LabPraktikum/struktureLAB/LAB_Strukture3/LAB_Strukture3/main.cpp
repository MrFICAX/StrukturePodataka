#include "BSTree.h"
void main()
{
	BSTree t;
	t.insert(3);
	t.insert(1);
	t.insert(5);
	t.insert(11);
	t.insert(8);
	t.insert(12);
	t.insert(5);
	t.insert(10);
	t.insert(2);
	t.insert(7);
	cout << t.diffLevel(t.vratiroot(), 1, 11);
	



    
}