#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;



class BSTNode
{
public:

	int key;
	BSTNode* left, *right;


public:


	BSTNode()
	{
		left = right = NULL;
	}

	BSTNode(int el)
	{
		key = el;
		left = right = NULL;
	}

	BSTNode(int el, BSTNode *le, BSTNode *de)
	{
		key = el;
		left = le;
		right = de;
	}

	void setEl(int el)
	{
		key = el;
	}

	int getEl()
	{
		return key;
	}

	bool isGT(int el)
	{
		return el < key;
	}

	bool isLT(int el)
	{
		return key < el;
	}

	bool isQT(int el)
	{
		return el == key;
	}

	void  visit()
	{
		cout << key << " ";
	}



};