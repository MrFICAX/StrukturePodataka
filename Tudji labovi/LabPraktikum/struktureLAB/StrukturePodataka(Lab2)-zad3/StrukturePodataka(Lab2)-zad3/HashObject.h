#pragma once
#include<iostream>
#include<string.h>
using namespace std;

class HashObject
{
protected:
	char key[20];
	int record;
public:
	HashObject()
	{
		strcpy(key, "sala");
		record = 0;
	}

	HashObject(char *k, int m)
	{
		strcpy(key, k);
		record = m;
	}

	HashObject(char *k)
	{
		strcpy(key, k);
		record = 0;
	}

	HashObject& operator= (HashObject const& obj)
	{
		strcpy(key, obj.key);
		record = obj.record;
		return *this;
	}

	bool operator== (HashObject& const obj)
	{
		return record == obj.record;
	}

	char* GetKey()
	{
		return key;
	}

	int GetRecord()
	{
		return record;
	}

	bool IsEqualKey(HashObject obj)
	{
		return strcmp(key, obj.key);
	}

	void Print()
	{
		cout << key << "|" << record;
	}

	void SetRecord(int a)
	{
		record = a;
	}

};