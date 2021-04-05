#include <iostream>
#include "ChainedHashTable.h"

void main()
{
	ChainedHashTable< char*, int > table(12);
	HashObject p1("if", NULL);
	table.insert(p1);
	p1 = HashObject("else", NULL);
	table.insert(p1);
	p1 = HashObject("switch", NULL);
	table.insert(p1);
	p1 = HashObject("cout", NULL);
	table.insert(p1);
	p1 = HashObject("cin", NULL);
	table.insert(p1);
	p1 = HashObject("break", NULL);
	table.insert(p1);
	p1 = HashObject("scanf", NULL);
	table.insert(p1);
	p1 = HashObject("printf", NULL);
	table.insert(p1);
	p1 = HashObject("while", NULL);
	table.insert(p1);
	p1 = HashObject("for", NULL);
	table.insert(p1);


	table.printTable();
}