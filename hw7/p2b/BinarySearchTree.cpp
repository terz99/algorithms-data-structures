#include <bits/stdc++.h>
#include "BinarySearchTree.h"
#include "LinkedList.h"
using namespace std;

/**
 * Default constructor. Sets the root Node element to NULL
*/
BinarySearchTree::BinarySearchTree(){
    this->root = NULL;
}

/**
 * Private method. Inserts a new element into the binary search tree.
 * It is called by its corresponding public method.
 * @param node the current node
 * @param data the element which is inserted
*/
void BinarySearchTree::insert(Node *node, const int& data){

    if(data <= node->data){
        if(node->left == NULL){
            node->left = new Node(data);
        } else {
            this->insert(node->left, data);
        }
    } else {
        if(node->right == NULL){
            node->right = new Node(data);
        } else {
            this->insert(node->right, data);
        }
    } 
}

/**
 * Public method. Inserts a new element into the binary search tree.
 * Calls its correspoding private method in order to insert the new element
 * @param data the new element which is inserted
*/
void BinarySearchTree::insert(const int& data){

    if(this->root == NULL){
        this->root = new Node(data);
        return;
    }
    this->insert(this->root, data);
}

/**
 * Private method. Makes a pre-order traversal of the tree and adds the elements
 * in a LinkedList which is provided by the user as an argument of the method.
 * @param node the current node
 * @param list the linked list
*/
void BinarySearchTree::toLinkedList(Node *node, LinkedList& list){
    if(node->right != NULL) this->toLinkedList(node->right, list);
    list.push(node->data);
    if(node->left != NULL) this->toLinkedList(node->left, list);
}

/**
 * Public method. Calls its corresponding private method and transforms
 * a binary search tree to a sorted linked list provided by the user.
 * @param node the current node
 * @param list the linked list
*/
void BinarySearchTree::toLinkedList(LinkedList& list){
    if(this->root == NULL){
        return;
    }
    this->toLinkedList(this->root, list);
}

