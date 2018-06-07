#include <bits/stdc++.h>
using namespace std;

class RBT{

    enum Color{RED, BLACK};

    class Node{
    public: 
        int data;
        Node *left, *right, *parent;
        Color color;
        Node(){
            left = right = parent = NULL;
        }
        Node(const int& data, Color color = RED, Node* parent = NULL){
            this->data = data;
            this->parent = parent;
            this->color = color;
            this->left = this->right = NULL;
        }
    };

    Node* root;

    Node* insertUtil(Node* p, const int& data){
        if(data < p->data){
            if(p->left) return insertUtil(p->left, data);
            else return p->left = new Node(data, RED, p);
        } else if(data > p->data){
            if(p->right) return insertUtil(p->right, data);
            else return p->right = new Node(data, RED, p);
        } else {
            return p;
        }
    }

    bool isRed(Node* p){
        if(p != NULL && p->color == RED) return true;
        return false;
    }

    string getColor(Node* p){
        if(isRed(p)) return "R";
        return "B";
    }

    void setColor(Node*& p, Color color){
        if(p != NULL) p->color = color;
    }

    void printUtil(Node* p){
        cout << p->data << getColor(p) << endl;
        if(p->left){
            cout << "Going left\n";
            printUtil(p->left);
            cout << "Going back\n";
        } 
        if(p->right){
            cout << "Going right\n";
            printUtil(p->right);
            cout << "Going back\n";
        }
    }

    void rotateLeft(Node*& x){
        Node *y = x->right;
        x->right = y->left;

        if(x->right != NULL){
            x->right->parent = x;
        }

        y->parent = x->parent;

        if(x->parent == NULL){
            root = y;
        } else if(x == x->parent->left){
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node*& x){
        Node* y = x->left;
        x->left = y->right;

        if(x->left != NULL){
            x->left->parent = x;
        }

        y->parent = x->parent;

        if(x->parent == NULL){
            root = y;
        } else if(x == x->parent->left){
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }

        y->right = x;
        x->parent = y;
    }

    void insertFixup(Node*& x){
        Node* p = x->parent;
        while(isRed(p)){
            Node* gp = p->parent;
            if(gp && gp->left == p){
                Node* uncle = gp->right;
                if(isRed(uncle)){
                    setColor(p, BLACK);
                    setColor(uncle, BLACK);
                    setColor(gp, RED);
                    x = gp;
                } else {
                    if(x == p->right){
                        rotateLeft(p);
                        x = p;
                        p = gp;
                    }
                    rotateRight(gp);
                    swap(p->color, gp->color);
                    x = p;
                }
            } else if(gp){

                Node* uncle = gp->left;
                if(isRed(uncle)){
                    setColor(p, BLACK);
                    setColor(uncle, BLACK);
                    setColor(gp, RED);
                    x = gp;
                } else {

                    if(x == p->left){
                        rotateRight(p);
                        x = p;
                        p = gp;
                    }
                    rotateLeft(gp);
                    swap(p->color, gp->color);
                    x = p;
                }
            }
        }
        setColor(root, BLACK);
    }

public: 

    RBT(){
        root = NULL;
    }

    void insert(const int& data){
        if(root == NULL){
            root = new Node(data, BLACK);
        } else {
            Node* tmp = insertUtil(root, data);
            insertFixup(tmp);
        }
    }

    void print(){
        if(root == NULL) return;
        printUtil(root);
    }
};

int main(){

    RBT t;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        t.insert(tmp);
    }

    t.print();

    return 0;
}