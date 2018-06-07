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
 * Method which pushesh a new element at the end of the linked list
 * @param elem {@code const int} passed by reference
*/
void LinkedList::push(const int& elem){

    if(this->start == NULL){
        this->start = new Node(elem);
        return;
    }

    Node *curr = this->start;
    while(curr->next != NULL) curr = curr->next;
    curr->next = new Node(elem);
}

/**
 * This method reverses the order of the list. It just reverses
 * the arrow which is pointing to the next. The algorithm is in-situ
 * because it does not create a new LinkedList, yet it just reverses
 * the arrows of the nodes of the current LinkedList. It uses three
 * helper pointers to {@code Node}, however they have constant memory,
 * therefore the algorithm being in-situ
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