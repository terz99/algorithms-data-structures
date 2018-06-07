#include <bits/stdc++.h>
#include "binarysearchtree.h"
using namespace std;

int main(){

    int n;
    cin >> n;
    BST bst;
    while(n--){
        int tmp;
        cin >> tmp;
        bst.insert(tmp);
    }

    bst.print();

    while(true){
        int tmp;
        cin >> tmp;
        if(tmp < 0){
            break;
        }
        bst.remove(tmp);
        bst.print();
    }

    return 0;
}