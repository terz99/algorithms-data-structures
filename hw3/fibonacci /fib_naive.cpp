/*
Title: n-th Fibonacci number using naive recursive approach
Author: Dushan Terzikj
Date: Feb 22. 2018

This program uses STDIN and STDOUT. 
Input: integer -> n
Output: n-th Fibonacci number
*/
#include <bits/stdc++.h>
using namespace std;

/* Returns the n-th fibonacci number */
long long fib(int n){
    
    if(n == 1 || n == 2){
        return 1;
    }

    return fib(n-1) + fib(n-2);
}

int main(){

    int n;
    cin >> n;

    while(n <= 0){
        cout << "Please enter a number greater than 0\n";
        cin >> n;
    }

    cout << fib(n) << endl;

    return 0;
}