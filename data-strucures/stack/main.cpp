#include <bits/stdc++.h>
#include "stack.h"
using namespace std;

int main(){
    
    int size;
    cin >> size;
    Stack s(size);
    for(int i = 0; i < size; i++){
        s.push(i);
    }

    while(!s.isEmpty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}