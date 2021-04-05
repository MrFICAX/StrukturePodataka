
#include"ChainedHashTable.h"
void main()
{
	ChainedHashTable t(32);
	HashObject a1(7569845, "Jovan Pesic");
	HashObject a2(7569855, "Mitar Pesic");
	HashObject a3(7569865, "Lazar Jovicevic");
	HashObject a4(7569829, "Sreten Lipcevic");
	HashObject a5(7569897, "Nikola Radosevic");
	t.Insert(a1);
	t.Insert(a2);
	t.Insert(a3);
	t.Insert(a4);
	t.Insert(a5);
	t.Print();
	t.Withdraw(a1);
	t.Print();
}