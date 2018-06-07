/*
Title: n-th Fibonacci number using closed form
Author: Dushan Terzikj
Date: Feb 22. 2018

This program uses STDIN and STDOUT. 
Input: integer -> n
Output: n-th Fibonacci number
*/
#include <bits/stdc++.h>
using namespace std;

/* Returns the a^n in O(lg(n)) */
double power(double a, int n){

    if(n == 0){
        return 1.0;
    } else if(n == 1){
        return a;
    } else {

        double ret = power(a, n/2);
        if(n%2 == 0){
            return ret*ret;
        }  else {
            return a*ret*ret;
        }
    }
}

/* Returns the n-th fibonacci number */
long long fib(int n){
    
    double phi = (1.0 + sqrt(5.0))/2.0; // golden ratio
    double tmp = power(phi, n);
    double ret = tmp/sqrt(5.0);

    return (long long)round(ret);
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
