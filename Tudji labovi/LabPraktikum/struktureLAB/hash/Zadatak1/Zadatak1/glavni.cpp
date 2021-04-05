#include"HashTable.h"
#include <stdlib.h>


void main()
{
	try
	{
		HashTable t(11);
		t.insert("char");
		t.insert("int");
		t.insert("int");
		t.insert("int");
		t.insert("int");
		t.insert("void");
		t.insert("NULL");
		t.insert("char");
		t.insert("unsigned");
		t.printALL();
		t.withdraw("char");
		cout << endl;
		t.printALL();
	}
	catch (char* p)
	{
		cout << "Error: " << p << endl;
	}
	catch (...)
	{
		cout << "!!!" << endl;
	}
	system("pause");
}