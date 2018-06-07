#include <bits/stdc++.h>
#include "LinkedList.h"
#include "BinarySearchTree.h"
using namespace std;

int main(){

    BinarySearchTree bst;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        bst.insert(tmp);
    }

    LinkedList list;
    bst.toLinkedList(list);
    list.print();

    return 0;
}