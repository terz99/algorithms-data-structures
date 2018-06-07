/*
Title: n-th Fibonacci number using bottom-up approach
Author: Dushan Terzikj
Date: Feb 22. 2018

This program measures time for this algorithm for increasing n 
Input: integer -> n
Output: n-th Fibonacci number
*/
#include <bits/stdc++.h>
using namespace std;

/* Returns the n-th fibonacci number */
long long fib(long long n){
    
    /* Two integers are used instead of an array.
    The reason for this is that N can become very large, thus
    the array[N] will require a lot of memory */

    if(n == 1 || n == 2){
        return 1;
    }

    long long f_minus_one = 1;
    long long f_minus_two = 1;
    long long f;

    for(long long i = 3; i <= n; i++){
        f = f_minus_one + f_minus_two;
        if(i != n){
            f_minus_two = f_minus_one;
            f_minus_one = f;
        }
    }

    return f;
}

int main(){

    ofstream out;
    out.open("fib_bottom_up.txt", ofstream::out);
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
            /* Handling long overflow case */
            break;
        }
    }

    return 0;
}
