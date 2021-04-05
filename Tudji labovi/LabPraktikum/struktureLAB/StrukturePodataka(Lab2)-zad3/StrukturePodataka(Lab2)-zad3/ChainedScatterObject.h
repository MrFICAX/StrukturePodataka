#pragma once
#include"ScatterObject.h"

class ChainedScatterObject :public ScatterObject
{
public:
	long next;
public:
	ChainedScatterObject() :ScatterObject(){ next = -1; }
	ChainedScatterObject(char* p) :ScatterObject(p){ next = -1; }
	ChainedScatterObject(char *p, int k) : ScatterObject(p, k){ next = -1; }
	ChainedScatterObject(char *p, int k, unsigned int n) :ScatterObject(p, k){ next = n; }
};