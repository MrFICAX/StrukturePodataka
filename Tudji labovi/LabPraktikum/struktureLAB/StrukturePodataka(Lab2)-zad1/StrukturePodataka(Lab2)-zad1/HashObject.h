#pragma once
#include <iostream>
using namespace std;

class HashObject
{
public:
	char * key;
	 int record;
public:
	HashObject() { this->key = 0; this->record = 0; };
	HashObject( char * kljluc, int record) { this->key = kljluc; this->record = record; }
	~HashObject(){};
	friend ostream& operator<< (ostream& out, HashObject & obj){ out << obj.key << " " << " -> "; return out; };
	friend bool operator==(HashObject & obj1, HashObject & obj2){ return obj1.key == obj2.key; }
};