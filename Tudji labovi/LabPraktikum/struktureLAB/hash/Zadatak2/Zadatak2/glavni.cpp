#include "HashTable.h"
#include <stdlib.h>



void main()
{
	HashTable *a = new HashTable(100);

	a->insert("Dimitrije", "Jovic", 1234567);
	a->insert("Darko", "Jotev",2345678);
	a->insert("Stanko", "Stankovic",3456789 );
	a->insert("Janko", "Petrovic",4567891 );
	a->insert("Ljubisa", "Preletacevic",5678912);

	a->printALL();
	cout << endl << endl;
	a->withdraw("Ljubisa", "Preletacevic",5678912);

	a->printALL();





	system("pause");











}