/*
Title: n-th Fibonacci number using naive recursive approach
Author: Dushan Terzikj
Date: Feb 22. 2018

This program measures running time as n increases 
Input: integer -> n
Output: n-th Fibonacci number
*/
#include <bits/stdc++.h>
using namespace std;

/* Returns the n-th fibonacci number */
long long fib(long long n){

    if(n == 1 || n == 2){
        return 1;
    }

    return fib(n-1) + fib(n-2);
}

int main(){

    ofstream out;
    out.open("fib_naive.txt", ofstream::out);
    out.precision(6);

    long long n = 1;
    while(true){


        out << n << endl;

        clock_t start_time = clock();
        fib(n);
        clock_t end_time = clock();
        out << fixed << (double)(end_time - start_time)/CLOCKS_PER_SEC << endl;

        if((double)(end_time - start_time)/CLOCKS_PER_SEC >= 5.0){
            break;
        }
        n += ((n >= 45) ? n : 3);

        if(n < 0){
            /* Handling long overflow cases */
            break;
        }
    }

    return 0;
}
