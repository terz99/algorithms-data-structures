#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

/**
 * Default constructor. Sets the start node to {@code NULL}
*/
LinkedList::LinkedList(){
    this->start = NULL;
}

/**
 * Method which pushesh a new element at the front of the linked list
 * @param elem {@code const int} passed by reference
*/
void LinkedList::push(const int& elem){
    if(this->start == NULL){
        this->start = new Node(elem);
        return;
    }
    Node *newnode = new Node(elem);
    newnode->next = this->start;
    this->start = newnode;
}

/**
 * This method reverses the order of the list. It just reverses
 * the arrow which is pointing to the next. The algorithm is in-situ
*/
void LinkedList::reverse(){

    if(this->start == NULL){
        return;
    }

    Node *next = NULL;
    Node *prev = NULL;
    Node *curr = this->start;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    this->start = prev;
}

/**
 * Method which prints the list
*/
void LinkedList::print(){

    if(this->start == NULL){
        return;
    }

    Node *curr = this->start;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}