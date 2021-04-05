#include<iostream>
#include "BirackiSpisak.h"
using namespace std;
void main()
{
	BirackiSpisak * spisak = new BirackiSpisak(10000);
	spisak->insert("1301996734501", "Marija", "Markovic");
	spisak->insert("2104197070553", "Igor", "Ognjanovic");
	spisak->insert("210419712553", "Milos", "Jovanovic");
	spisak->insert("119412553", "Aleksandar", "Kovacevic");
	spisak->insert("119412553", "Milan", "Kovacevic");
	spisak->print();




}