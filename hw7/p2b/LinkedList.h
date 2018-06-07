#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <bits/stdc++.h>
using namespace std;

/**
 * This class represents a linked list. It stores the start node
 * as a root. Each Node element has a data associated to it and 
 * a pointer which points to the next element.
*/
class LinkedList{

private: 

    class Node{

    public: 
        int data;
        Node *next;
        Node(){}
        Node(const int& data){
            this->data = data;
            this->next = NULL;
        }
    };

    Node *start;

public: 

    LinkedList();
    void push(const int& elem);
    void reverse();
    void print();
};

#endif // !_LINKED_LIST_H