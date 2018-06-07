#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

class BinarySearchTree{

private:

    class Node{
    public: 
        int data;
        Node *left;
        Node *right;
        Node(){}
        Node(const int& data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
    };

    Node *root;

    void insert(Node *node, const int& data);
    void toLinkedList(Node *node, LinkedList& list);

public: 

    BinarySearchTree();
    void insert(const int& data);
    void toLinkedList(LinkedList& list);
};

#endif // !_BINARY_SEARCH_TREE_H