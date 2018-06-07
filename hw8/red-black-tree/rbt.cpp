#include <bits/stdc++.h>
#include "rbt.h"
using namespace std;


Node::Node(const int& data){
    this->data = data;
    this->color = RED;
    left = right = parent = NULL;
}

string RedBlackTree::getColorString(Node*& ptr){
    if(ptr->color == RED){
        return "R";
    }
    return "B";
}

void RedBlackTree::setColor(Node*& node, Color color){
    if(node == NULL){
        return;
    }
    node->color = color;
}

void RedBlackTree::flipColors(Node*& uncle, Node*& parent, Node*& grandparent){
    out << "Fliping colors between uncle: " << uncle->data << " parent: " << parent->data << " grandparent: " << grandparent->data << endl;
    setColor(uncle, BLACK);
    setColor(parent, BLACK);
    setColor(grandparent, RED);
}

bool RedBlackTree::isRed(Node* node){
    return node != NULL && node->color == RED;
}

Node* RedBlackTree::insert(Node*& root, Node*& ptr){
    if(root == NULL){
        return ptr;
    }

    if(ptr->data < root->data){
        root->left = insert(root->left, ptr);
        root->left->parent = root;
    } else if(ptr->data > root->data){
        root->right = insert(root->right, ptr);
        root->right->parent = root;
    }

    return root;
}

Node* RedBlackTree::getMinimum(Node* node){
    if(node == NULL) return NULL;
    if(node->left == NULL){
        return node;
    }
    return getMinimum(node->left);
}

Node* RedBlackTree::getMaximum(Node* node){
    if(node == NULL) return NULL;
    if(node->right == NULL){
        return node;
    }
    return getMaximum(node->right);
}

Node* RedBlackTree::search(Node* node, int data){
    if(node == NULL){
        return NULL;
    }

    if(data < node->data){
        return search(node->left, data);
    } else if(data > node->data){
        return search(node->right, data);
    } else {
        return node;
    }
}

Node* RedBlackTree::deleteValue(Node*& root, int data){

    if(root == NULL){
        return root;
    }

    if(data < root->data){
        return deleteValue(root->left, data);
    }

    if(data > root->data){
        return deleteValue(root->right, data);
    }

    if(root->left == NULL || root->right == NULL){
        return root;
    }

    Node* tmp = getMinimum(root->right);
    root->data = tmp->data;
    return deleteValue(root->right, tmp->data);
}

void RedBlackTree::fixInsertViolation(Node*& ptr){

    Node* parent = NULL;
    Node* grandparent = NULL;
    while(ptr != root && isRed(ptr) && isRed(ptr->parent)){

        parent = ptr->parent;
        grandparent = parent->parent;
        if(parent == grandparent->left){
            Node* uncle = grandparent->right;
            if(isRed(uncle)){
                flipColors(uncle, parent, grandparent);
                ptr = grandparent;
            } else {

                if(ptr == parent->right){
                    rotateLeft(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }

                rotateRight(grandparent);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
        } else {

            Node* uncle = grandparent->left;
            if(isRed(uncle)){
                flipColors(uncle, parent, grandparent);
                ptr = grandparent;
            } else {

                if(ptr == parent->left){
                    rotateRight(parent);
                    ptr = parent;
                    parent = parent->parent;
                }

                rotateLeft(grandparent);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
        }
    }

    setColor(root, BLACK);
}

void RedBlackTree::fixDeleteViolation(Node*& node){

    if(node == NULL){
        return;
    }

    if(node == root){
        if(root->right == NULL && root->left == NULL){
            root = NULL;
        } else {
            if(root->right != NULL){
                root->data = root->right->data;
                root->right = NULL;
            } else {
                root->data = root->left->data;
                root->left = NULL;
            }
        }
        return;
    }

    if(isRed(node) || isRed(node->left) || isRed(node->right)){
        
        Node* child = ((node->left != NULL) ? node->left : node->right);
        if(node == node->parent->left){
            node->parent->left = child;
            if(child != NULL){
                child->parent = node->parent;
            }
            setColor(child, BLACK);
            delete node;
        } else {
            node->parent->right = child;
            if(child != NULL){
                child->parent = node->parent;
            }
            setColor(child, BLACK);
            delete node;
        }
    } else {

        Node* sibling = NULL;
        Node* parent = NULL;
        Node* ptr = node;
        setColor(ptr, DOUBLE_BLACK);
        while(ptr != root && ptr->color == DOUBLE_BLACK){
            parent = ptr->parent;
            if(ptr == parent->left){
                sibling = parent->right;
                if(isRed(sibling)){
                    setColor(sibling, BLACK);
                    setColor(parent, RED);
                    rotateLeft(parent);
                } else {

                    if(!isRed(sibling->left) && !isRed(sibling->right)){
                        setColor(sibling, RED);
                        if(isRed(parent)){
                            setColor(parent, BLACK);
                        } else {
                            setColor(parent, DOUBLE_BLACK);
                        }
                        ptr = parent;
                    } else {

                        if(!isRed(sibling->right)){
                            setColor(sibling->left, BLACK);
                            setColor(sibling, RED);
                            rotateRight(sibling);
                            sibling = parent->right;
                        }

                        setColor(sibling, parent->color);
                        setColor(parent, BLACK);
                        setColor(sibling->right, BLACK);
                        rotateLeft(parent);
                        break;
                    }
                }
            } else {

                sibling = parent->left;
                if(isRed(sibling)){
                    setColor(sibling, BLACK);
                    setColor(parent, RED);
                    rotateRight(parent);
                } else {

                    if(!isRed(sibling->left) && !isRed(sibling->right)){

                        setColor(sibling, RED);
                        if(isRed(parent)){
                            setColor(parent, BLACK);
                        } else {
                            setColor(parent, DOUBLE_BLACK);
                        }
                        ptr = parent;
                    } else {

                        if(!isRed(sibling->left)){
                            setColor(sibling->left, BLACK);
                            setColor(sibling, RED);
                            rotateLeft(sibling);
                            sibling = parent->left;
                        }

                        setColor(sibling, parent->color);
                        setColor(parent, BLACK);
                        setColor(sibling->left, BLACK);
                        rotateRight(parent);
                        break;
                    }
                }
            }
        }

        if(node == node->parent->left){
            node->parent->left = NULL;
        } else {
            node->parent->right = NULL;
        }
        delete node;
        setColor(root, BLACK);
    }
}


void RedBlackTree::rotateLeft(Node*& ptr){

    out << "Left rotate at: " << ptr->data << getColorString(ptr) << endl;

    Node *right_child = ptr->right;
    ptr->right = right_child->left;

    if(ptr->right != NULL){
        ptr->right->parent = ptr;
    }

    right_child->parent = ptr->parent;

    if(ptr->parent == NULL){
        root = right_child;
    } else if(ptr == ptr->parent->left){
        ptr->parent->left = right_child;
    } else {
        ptr->parent->right = right_child;
    }

    right_child->left = ptr;
    ptr->parent = right_child;
}

void RedBlackTree::rotateRight(Node*& ptr){

    out << "Right rotate at: " << ptr->data << getColorString(ptr) << endl;

    Node* left_child = ptr->left;
    ptr->left = left_child->right;

    if(ptr->left != NULL){
        ptr->left->parent = ptr;
    }

    left_child->parent = ptr->parent;

    if(ptr->parent == NULL){
        root = left_child;
    } else if(ptr == ptr->parent->left){
        ptr->parent->left = left_child;
    } else {
        ptr->parent->right = left_child;
    }

    left_child->right = ptr;
    ptr->parent = left_child;
}


RedBlackTree::RedBlackTree(){
    cnt = 0;
    root = NULL;
    out.open("solution_b.txt", ios::out);
}

RedBlackTree::~RedBlackTree(){
    root = NULL;
    out.close();
}

void RedBlackTree::insert(int data){
    out << "Insertion #" << cnt++ << endl;
    Node* node = new Node(data);
    root = insert(root, node);
    fixInsertViolation(node);
}

void RedBlackTree::deleteNode(Node*& p){
    Node* node = deleteValue(root, p->data);
    fixDeleteViolation(node); 
}

Node* RedBlackTree::predecessor(Node*& node){
    
    Node* curr = node;
    if(curr->left != NULL){
        return getMaximum(curr->left);
    }

    Node* p = curr->parent;
    while(p != NULL && curr == p->left){
        curr = p;
        p = p->parent;
    }
    return p;
}

Node* RedBlackTree::successor(Node*& node){

    Node* curr = node;
    if(curr->right != NULL){
        return getMinimum(curr->right);
    }

    Node* p = curr->parent;
    while(p != NULL && curr == p->right){
        curr = p;
        p = p->parent;
    }
    return p;
}

Node* RedBlackTree::getMinimum(){
    return getMinimum(root);
}

Node* RedBlackTree::getMaximum(){
    return getMaximum(root);
}

Node* RedBlackTree::search(int data){
    return search(root, data);
}

void RedBlackTree::print(){
    if(root == NULL){
        return;
    }
    out << "Preorder traversal: ";
    print(root);
    out << endl << endl;
}

void RedBlackTree::print(Node*& node){
    out << node->data << getColorString(node) << " ";
    if(node->left != NULL) print(node->left);
    if(node->right != NULL) print(node->right);
}

void RedBlackTree::print(Node*& node, ofstream& out){
    out << node->data << getColorString(node) << " ";
    if(node->left != NULL) print(node->left, out);
    if(node->right != NULL) print(node->right, out);
}

void RedBlackTree::print(ofstream& out){
    if(root == NULL){
        return;
    }
    print(root, out);
    out << endl;
}