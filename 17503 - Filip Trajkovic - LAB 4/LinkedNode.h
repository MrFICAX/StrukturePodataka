#pragma once

#include <iostream>
#include "Edge.h"

using namespace std;

template<class T>
class Edge;

template <class T>
class LinkedNode {
public:
	T node;
	Edge<T>* adj;
	LinkedNode<T>* next;
	int status;
	int duzinaPuta;
	LinkedNode<T>* prev;
public:
	inline LinkedNode() {
		adj = NULL;
		next = NULL;
		prev = NULL;
		duzinaPuta = INT_MAX;
		status = 0;
	}
	inline LinkedNode(T nodeN) {
		node = nodeN;
		adj = NULL;
		next = NULL;
		prev = NULL;
		duzinaPuta = INT_MAX;
		status = 0;
	}
	inline LinkedNode(T nodeN, Edge<T>* adjN, LinkedNode<T>* nextN, int statusN)
	{
		node = nodeN;
		adj = adjN;
		next = nextN;
		status = statusN;
		prev = NULL;
		duzinaPuta = INT_MAX;
	}
		inline void Visit() {
		cout << node << endl;
	}
};
