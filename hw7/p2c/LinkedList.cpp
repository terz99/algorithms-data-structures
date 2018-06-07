#include <bits/stdc++.h>
#include "LinkedList.h"
#include "BinarySearchTree.h"
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

/**
 * Private method. Turns the linked list into a binary search tree and saves it
 * into the parameter {@code bst}. It uses a divide and conquer method. Here are the steps:
 * 1. If {@code st > en} then stop. Otherwise continue to step 2.
 * 2. Find the middle element of the list, i.e., the element on position {@code mid:=(st+en)/2}.
 *    insert that element into {@code bst}. This is at most {@code n/2} operations which means
 *    the complexity is rougly {@code O(n)}.
 * 3. Recursively call this method on list sizes ranging {@code from st to mid-1} and {@code from mid+1 to en}.
 *    Proceed to step 1.
 * If the linked list is sorted, then the BST will be balanced, otherwise, no guarantee.
 * @param bst passed by reference
 * @param st starting index of the list of the current recursive call
 * @param en ending index of the list of the current recursive call
*/
void LinkedList::toBST(BinarySearchTree& bst, const int st, const int en){

    if(st > en){
        return;
    }

    Node *curr = this->start;
    int mid = (st+en)/2;
    int cnt = mid;
    while(cnt--){
        curr = curr->next;
    }
    bst.insert(curr->data);
    this->toBST(bst, st, mid-1);
    this->toBST(bst, mid+1, en);
}

/**
 * Public method. Calls its corresponding private method and turns a linked list into a binary serach tree
 * @param bst the resulting binary tree passed by reference
*/
void LinkedList::toBST(BinarySearchTree& bst){
    if(this->start == NULL){
        return;
    }
    Node *curr = this->start;
    int len = 0;
    while(curr != NULL){
        len++;
        curr = curr->next;
    }
    this->toBST(bst, 0, len-1);
}