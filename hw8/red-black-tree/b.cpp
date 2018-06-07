#include <bits/stdc++.h>
#include "rbt.h"
using namespace std;

int main(){

    int arr[] = {14, 42, 35, 7, 26, 17};

    RedBlackTree tree;
    for(int i = 0; i < 6; i++){
        tree.insert(arr[i]);
        tree.print();
    }

    return 0;
}