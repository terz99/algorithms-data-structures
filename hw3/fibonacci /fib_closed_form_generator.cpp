/*
Title: n-th Fibonacci number using closed form
Author: Dushan Terzikj
Date: Feb 22. 2018

This program measures running time for increasing n
Input: integer -> n
Output: n-th Fibonacci number
*/
#include <bits/stdc++.h>
using namespace std;

/* Returns the a^n in O(lg(n)) */
double power(double a, long long n){


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
long long fib(long long n){
    
    double phi = (1.0 + sqrt(5.0))/2.0; // golden ratio
    double tmp = power(phi, n);
    double ret = tmp/sqrt(5.0);

    return (long long)round(ret);
}

int main(){

    ofstream out;
    out.open("fib_closed_form.txt", ofstream::out);
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
