#pragma once
#include "LinkedNode.h"

using namespace std;

template<class T>
class LinkedNode;

template <class T>
class Edge {
public:
	LinkedNode<T>* dest;
	Edge<T>* link;
public:
	inline Edge() {
		dest = NULL;
		link = NULL;
	}
	inline Edge(LinkedNode<T>* destN, Edge<T>* linkN) : dest(destN), link(linkN) {}
};