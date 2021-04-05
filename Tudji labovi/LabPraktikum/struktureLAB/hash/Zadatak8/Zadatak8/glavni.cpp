#include "HashTable.h"



void main()
{
	try
	{


		HashTable *a=new HashTable(10);

		a->insert("dragan", "jankovic", 1234567);
		a->insert("janko", "jankovic", 1234867);
		a->insert("janko", "jankovic", 1234167);
		a->insert("janko", "jankovic", 1230167);
		
		a->printTable();
		cout << "***IZBACENI***" << endl << endl << endl;
		a->withdraw(1234167);
		cout << "***TABLICA****" << endl << endl << endl;
		a->printTable();
	}
	catch (char* e)
	{
		cout << e << endl;
	}
	system("pause");


}