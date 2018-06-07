/*
Title: n-th Fibonacci number using bottom-up approach
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
    
    long long f[n+1];
    f[1] = 1;
    f[2] = 1;

    for(int i = 3; i <= n; i++){
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];
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