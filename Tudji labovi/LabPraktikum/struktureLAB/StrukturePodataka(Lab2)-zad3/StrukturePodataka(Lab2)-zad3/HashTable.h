#pragma once
#include"HashObject.h"
#include<iostream>
#include<math.h>
using namespace std;

class HashTable
{
protected:
	unsigned int length;  //velcina tablice
	unsigned int count;  //broj elemenata u tablici
protected:
	unsigned int h(HashObject obj)   //hash f-ja metod deljenja
	{
		return (f(obj.GetKey()) % length);
	}

	virtual unsigned int f(int i)
	{
		return abs(i);
	}

	virtual unsigned int f(double d)
	{
		if (d == 0)
			return 0U;
		else
		{
			int exponent;
			double mantisa = frexp(d, &exponent);
			return (unsigned int)(2 * fabs(mantisa) - 1)*~0U; //broj od 0-1 pomnozen sa 2^31
		}
	}

	virtual unsigned int f(char *s)
	{
		unsigned int res = 0;
		unsigned int a = 7;  //ASCII kod je 7-bitni
		for (int i = 0; s[i] != 0; i++)
			res = res << a^s[i];   //<<shift, ^ XOR
		return res;
	}



	//
	virtual unsigned int g(unsigned int i)
	{
		return (i + 1) % length;
	}
	//




public:
	unsigned int GetLength(){ return length; }

	virtual double GetLoadFactor()
	{
		return (double)count / (double)length;
	}

};