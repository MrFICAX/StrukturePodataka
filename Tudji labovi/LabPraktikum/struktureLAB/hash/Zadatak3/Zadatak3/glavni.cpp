#include"HashTable.h"
#include <stdlib.h>

void main()
{
	try
	{
		HashTable t(11);
		t.insert("char");
		t.insert("int");
		t.insert("void");
		t.insert("int");
		t.insert("int");
		t.insert("char");
		t.insert("char");
		t.insert("int");
		
		t.print();
	}
	catch (char* a)
	{
		cout << "Error: " << a << endl;
	}
	catch (...)
	{
		cout << "!!!" << endl;
	}
	system("pause");
}