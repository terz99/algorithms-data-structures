#include "rbt.h"
#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v;
    for(int i = 1; i <= 5; i++){
        v.push_back(i);
    }

    ofstream out("solution_a.txt", ios::out);
    map<string, bool> m;
    do{
        RedBlackTree tree;
        for(auto el : v){
            tree.insert(el);
        }
        tree.print(out);
    } while(next_permutation(v.begin(), v.end()));
    out.close();

    return 0;
}