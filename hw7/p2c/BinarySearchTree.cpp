#include <bits/stdc++.h>
#include "BinarySearchTree.h"
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
 * Private method. Prints the tree in inorder traversal (left, root, right).
*/
void BinarySearchTree::print(Node *node){

    if(node->left != NULL) this->print(node->left);
    cout << node->data << " ";
    if(node->right != NULL) this->print(node->right);
}

/**
 * Prints the tree in inorder traversal (left, root, right).
*/
void BinarySearchTree::print(){
    if(this->root == NULL){
        return;
    }
    this->print(this->root);
    cout << endl;
}

