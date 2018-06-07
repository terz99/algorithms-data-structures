#include <bits/stdc++.h>
#include "rbt.h"
using namespace std;

int main(){

    RedBlackTree tree;
    bool flag = true;
    while(flag){

        char op;
        int tmp;
        Node* node = NULL;
        cin >> op;
        switch(op){
            case 'i':
                cin >> tmp;
                tree.insert(tmp);
                break;
            case 'p':
                tree.print();
                break;
            case 'd':
                cin >> tmp;
                node = tree.search(tmp);
                if(node)
                    tree.deleteValue(node);
                break;
            case 'l': 
                node = tree.getMinimum();
                if(node)
                    cout << node->data << endl;
                break;
            case 'h':
                node = tree.getMaximum();
                if(node)
                    cout << node->data << endl;
                break;
            case 's':
                cin >> tmp;
                node = tree.search(tmp);
                if(node){
                    Node* node1 = tree.successor(node);
                    if(node1){
                        cout << node1->data << endl;
                    }
                }
                break;
            case 'r': 
                cin >> tmp;
                node = tree.search(tmp);
                if(node){
                    Node* node1 = tree.predecessor(node);
                    if(node1){
                        cout << node1->data << endl;
                    }
                }
                break;
            case 'q':
                flag = false;
                break;
        }
    }

    return 0;
}