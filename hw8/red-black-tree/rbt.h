#ifndef _RED_BLACK_TREE
#define _RED_BLACK_TREE

#include <bits/stdc++.h>
using namespace std;

enum Color{RED, BLACK, DOUBLE_BLACK};

struct Node{
    int data;
    Color color;
    Node *left, *right, *parent;
    Node(const int& data);
};

class RedBlackTree{
private: 
    int cnt;
    ofstream out;
    Node* root;
    string getColorString(Node*& ptr);
    bool isRed(Node* node);
    void setColor(Node*& node, Color color);
    void flipColors(Node*& uncle, Node*& parent, Node*& grandparent);
    Node* insert(Node*& node, Node*& newNode);
    void print(Node*& node);
    void print(Node*& node, ofstream& out);
    Node* getMinimum(Node* node);
    Node* getMaximum(Node* node);
    Node* search(Node* node, int data);
    Node* deleteValue(Node*& node, int data);
    void fixInsertViolation(Node*& ptr);
    void fixDeleteViolation(Node*& node);

protected:
    void rotateLeft(Node*& h);
    void rotateRight(Node*& h);
public: 
    RedBlackTree();
    ~RedBlackTree();
    void insert(int data);
    void deleteNode(Node*& p);
    Node* predecessor(Node*& node);
    Node* successor(Node*& node);
    Node* getMinimum();
    Node* getMaximum();
    Node* search(int data);
    void print();
    void print(ofstream& out);
};

#endif // !_R_B_TREE