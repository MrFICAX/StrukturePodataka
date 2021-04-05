#pragma once
#include<iostream>
using namespace std;
#include<string.h>

class HashObject
{
public:
	unsigned int key;
	char record[40];  //podaci o pretplatniku
public:
	HashObject(unsigned int i, char *s)
	{
		key = i;
		strcpy(record, s);
	}

	HashObject(const HashObject& v)
	{
		key = v.key;
		strcpy(record, v.record);
	}

	HashObject()
	{
		key = 0;
		strcpy(record, "");
	}

	unsigned int GetKey()
	{
		return key;
	}

	void Print()
	{
		cout << "(" << record << ", " << key << ")";
	}

	bool operator==(HashObject v)
	{
		return key == v.GetKey();
	}

	~HashObject() {}
};