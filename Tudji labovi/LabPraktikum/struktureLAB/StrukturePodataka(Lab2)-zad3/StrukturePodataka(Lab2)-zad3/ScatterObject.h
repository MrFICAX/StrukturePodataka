#pragma once
#include"HashObject.h"

class ScatterObject : public HashObject
{
public:
	bool free;  //ova pozizicija u nizu je slobodna
public:
	ScatterObject() : HashObject(){}
	ScatterObject(char* p) :HashObject(p){}
	ScatterObject(char* p, int obj) : HashObject(p, obj){}

};