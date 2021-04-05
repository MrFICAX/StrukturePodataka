#include <iostream>
#include "ChainedScatterTable.h"

void main()
{
	ChainedScatterTable table(12);
	ChainedScatterObject p1("if", 12);
	table.Insert(p1);
	p1 = ChainedScatterObject("else", 13);
	table.Insert(p1);
	p1 = ChainedScatterObject("switch", 14);
	table.Insert(p1);
	p1 = ChainedScatterObject("cout", 15);
	table.Insert(p1);
	p1 = ChainedScatterObject("cin", 16);
	table.Insert(p1);
	p1 = ChainedScatterObject("break", 17);
	table.Insert(p1);
	p1 = ChainedScatterObject("scanf", 18);
	table.Insert(p1);
	p1 = ChainedScatterObject("printf", 19);
	table.Insert(p1);
	p1 = ChainedScatterObject("while", 20);
	table.Insert(p1);
	p1 = ChainedScatterObject("for", 21);
	table.Insert(p1);


	table.Display();
}