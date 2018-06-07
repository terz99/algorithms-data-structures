#include <bits/stdc++.h>
using namespace std;

#ifndef _STACK_H
#define _STACK_H

class Stack{
    int sz;
    int curr;
    int *arr;

public:
    Stack(){
        curr = 0;
        sz = 10;
        arr = new int[sz];
    }

    Stack(int sz){
        curr = 0;
        this->sz = sz;
        arr = new int[sz];
    }

    ~Stack(){
        curr = sz = 0;
        delete[] arr;
    }

    void push(int x){
        assert(curr < sz);
        arr[curr++] = x;
    }

    int top(){
        assert(curr > 0);
        return arr[curr-1];
    }

    int pop(){
        assert(curr > 0);
        int ret = arr[curr-1];
        curr--;
        return ret;
    }

    int size(){
        return sz;
    }

    int isEmpty(){
        return curr == 0;
    }
};

#endif // !_STACK_H