#include <bits/stdc++.h>
using namespace std;

#ifndef _BST_H
#define _BST_H

class Node{
public: 
    int data;
    Node *left, *right, *parent;
    Node(){
        left = right = parent = NULL;
    }
    Node(const int& data, Node* parent){
        this->data = data;
        left = right = NULL;
        this->parent = parent;
    }
};

class BST{

    Node* root;

    void xchg(int& a, int& b){
        int tmp = a;
        a = b;
        b = tmp;
    }

    void insertUtil(Node* p, const int& data){
        if(data < p->data){
            if(p->left){
                insertUtil(p->left, data); 
            } else {
                p->left = new Node(data, p);
            }
        } else {
            if(p->right){
                insertUtil(p->right, data);
            } else {
                p->right = new Node(data, p);
            }
        }
    }

    void printUtil(Node* p){
        cout << p->data << endl;
        if(p->left){
            cout << "Going left\n";
            printUtil(p->left);
            cout << "Going back up\n";
        }
        if(p->right){
            cout << "Going right\n"; 
            printUtil(p->right);
            cout << "Going back up\n";
        }
    }

    Node* searchUtil(Node* p, const int& data){
        if(data < p->data){
            if(p->left) return searchUtil(p->left, data);
            else return NULL;
        } else if(data > p->data){
            if(p->right) return searchUtil(p->right, data);
            else return NULL;
        } else {
            return p;
        }
    }

    Node* getMinimum(Node* p){
        if(p->left) return getMinimum(p->left);
        return p;
    }

public:

    BST(){
        root = NULL;
    }

    void insert(const int& data){
        if(root == NULL){
            root = new Node(data, NULL);
        } else {
            insertUtil(root, data);
        }
    }

    void print(){
        if(root == NULL) return;
        printUtil(root);
    }

    Node* search(const int& data){
        if(root == NULL) return NULL;
        return searchUtil(root, data);
    }

    void remove(const int data){
        Node* tmp = search(data);
        if(tmp == NULL) return;
        if(tmp->left == NULL && tmp->right == NULL){
            if(tmp->parent->left == tmp) tmp->parent->left = NULL;
            else tmp->parent->right = NULL;
            delete tmp;
        } else if(tmp->left == NULL){
            if(tmp->parent->left == tmp){ 
                tmp->parent->left = tmp->right;
                tmp->right->parent = tmp->parent;
            } else {
                tmp->parent->right = tmp->right;
                tmp->right->parent = tmp->parent;
            }
            delete tmp;
        } else if(tmp->right == NULL){
            if(tmp->parent->left == tmp){ 
                tmp->parent->left = tmp->left;
                tmp->left->parent = tmp->parent;
            } else {
                tmp->parent->right = tmp->left;
                tmp->left->parent = tmp->parent;
            }
            delete tmp;
        } else {
            Node* temp = getMinimum(tmp->right);
            int delValue = tmp->data;
            xchg(tmp->data, temp->data);
            remove(delValue);
        }
    }

};

#endif // !_BST_H
