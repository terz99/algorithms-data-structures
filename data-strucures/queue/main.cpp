#include <bits/stdc++.h>
#include "queue.h"
using namespace std;

int main(){

    int sz;
    cin >> sz;
    Queue q(sz);
    for(int i = 0; i < sz; i++){
        q.push(i);
    }

    while(!q.isEmpty()){
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}