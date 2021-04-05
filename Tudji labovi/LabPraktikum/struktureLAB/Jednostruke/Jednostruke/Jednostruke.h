#include <iostrem>
#pragma once
using namespace std;
 template <class T>
 class SLLNode
 {
 public:
	 T info;
	 SLLNode<T>* next;
 public:
	 SLLNode(){
		 next = NULL;
	 }
	 SLLNode(T i){
		 info = i;
		 next = NULL;

	 }
	 SLLNode(T i, SLLNode<T>*n)
	 {
		 info = i;
		 next = n;
	 }
	 ~SLLNode()
	 {

	 }
	 T print()
	 {
		 return info;
	 }
	 bool isEqual(T el)
	 {
		 return el == info;
	 }

 };