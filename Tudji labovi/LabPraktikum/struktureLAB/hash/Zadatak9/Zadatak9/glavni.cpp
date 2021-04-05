#include "HashTable.h"

void main()
{
	try{
		HashTable h1(502);

		h1.insert("int");
		h1.insert("char");
		h1.insert("void");
		h1.insert("int");
		h1.insert("char");
		h1.insert("void");
		h1.insert("unsigned");
		h1.print();
		cout << "*****Izbaceni****" << endl;
		h1.withdraw("void");
		h1.withdraw("int");
		h1.withdraw("void");
		cout << "***Tablica***" << endl;
		h1.print();
	}
	catch (char* e)
	{
		cout << e << endl;
	}
	system("pause");
}