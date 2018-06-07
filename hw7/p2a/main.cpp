#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

int main(){

    LinkedList list;
    for(int i = 0; i < 5; i++){
        list.push(i);
    }

    list.print();

    list.reverse();

    list.print();

    return 0;
}