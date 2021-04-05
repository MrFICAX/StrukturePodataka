#pragma once
#include "HashTable.h"
#include <stdlib.h>



void main()
{
	try
	{
		HashTable* a = new HashTable(19);
		a->setEl("Stanko", "Jankovic", 1234567);
		a->setEl("Janko", "Stankovic", 1434567);
		a->setEl("Sanko", "Jankovic", 1234867);
		a->setEl("Janko", "Lukovic", 1234467);
		a->setEl("Janko", "Jankovic", 1224567);
		a->setEl("Jako", "Jankovic", 1239567);
		a->setEl("Janko", "Jaovic", 3234567);

		a->printAll();
	}
	catch (char* e)
	{
		cout << e << endl;
	}
	system("pause");
}