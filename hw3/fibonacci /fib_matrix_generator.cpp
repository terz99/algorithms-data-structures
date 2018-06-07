/*
Title: n-th Fibonacci number using matrices
Author: Dushan Terzikj
Date: Feb 22. 2018

This program measures running time as n increases 
Input: integer -> n
Output: n-th Fibonacci number
*/
#include <bits/stdc++.h>
using namespace std;

/* Multiplies F with M */
void multiply(long long F[2][2], long long M[2][2]){

    long long tmp[2][2] = {{0, 0}, {0, 0}};
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                tmp[i][j] += F[i][k]*M[k][j];
            }
        }
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            F[i][j] = tmp[i][j];
        }
    }
}

/* Returns the F^n */
void power(long long F[2][2], long long n){


    if(n == 0 || n == 1){
        return;
    }

    power(F, n/2);
    multiply(F, F);

    long long M[2][2] = {{1, 1}, {1, 0}};
    if(n%2){
        multiply(F, M);
    }
}

/* Returns the n-th fibonacci number */
long long fib(int n){
    if(n == 1 || n == 2){
        return 1;
    }

    long long F[2][2] = {{1, 1}, {1, 0}};
    power(F, n);

    return F[0][1];
}

int main(){

    ofstream out;
    out.open("fib_matrix.txt", ofstream::out);
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
