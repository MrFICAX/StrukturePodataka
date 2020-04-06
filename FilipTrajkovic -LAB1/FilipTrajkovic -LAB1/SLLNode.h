#pragma once
using namespace std;

template <class N>
class SLLNode {
public:
    N info;
    SLLNode<N>* next;

    SLLNode() {
        next = NULL;
    }
    SLLNode(N n) {
        info = n;
        next = NULL;
    }
    SLLNode(N n, SLLNode<N>* t) {
        info = n;
        next = t;
    }
    ~SLLNode() {

    }
    N stampajElement() {
        return info;
    }
    bool Jednaki(N n) {
        return n == info;
    }

};