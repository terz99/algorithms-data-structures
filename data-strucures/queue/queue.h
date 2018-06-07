#include <bits/stdc++.h>
using namespace std;

#ifndef _QUEUE_H
#define _QUEUE_H

class Queue{
    int tail, head;
    int sz;
    int *arr;

public:

    Queue(){
        tail = head = 0;
        sz = 10;
        arr = new int[sz];
    }

    Queue(int sz){
        this->sz = sz;
        tail = head = 0;
        arr = new int[sz];
    }

    ~Queue(){
        sz = tail = head;
        delete[] arr;
    }

    void push(int x){
        assert((head+1)%sz != tail);
        arr[head++] = x;
        head %= sz;
    }

    int front(){
        assert(head != tail);
        return arr[tail];
    }

    void pop(){
        assert(head != tail);
        tail = (tail+1)%sz;
    }

    int size(){
        return sz;
    }

    bool isEmpty(){
        return head == tail;
    }
};

#endif // !_QUEUE_H