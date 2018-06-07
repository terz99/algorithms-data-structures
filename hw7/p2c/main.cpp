#include <bits/stdc++.h>
#include "LinkedList.h"
#include "BinarySearchTree.h"
using namespace std;

int main(){

    BinarySearchTree bst;
    LinkedList list;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        list.push(tmp);
    }

    list.print();
    list.toBST(bst);
    bst.print();

    return 0;
}