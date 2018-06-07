#include <bits/stdc++.h>
#include "algorithm.h"
using namespace std;

int main(){

    ofstream out;
    srand(time(NULL));
    const int MAX = 32000;

    if(!out.is_open()){
        out.open("data_dp.txt", ios::out);
    }
    if(!out.good()){
        exit(1);
    }
    for(int n = 2; n <= 32000; n += MAX/100){
        vector< vector<int> > mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                mat[i][j] = rand()%10000 + 1;
            }
        }
        Solution sol(n, mat);
        clock_t st = clock();
        sol.solve();
        clock_t ft = clock();
        double t = (double)(ft-st)/CLOCKS_PER_SEC;
        out << n << endl << t << endl;
        if(t > 5.0) break;
    }
    out.close();

    if(!out.is_open()){
        out.open("data_bruteforce.txt", ios::out);
    }
    if(!out.good()){
        exit(1);
    }

    for(int n = 2; n <= 100; n++){
        vector< vector<int> > mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                mat[i][j] = rand()%10000 + 1;
            }
        }
        Solution sol(n, mat);
        clock_t st = clock();
        sol.solveBruteforce();
        clock_t ft = clock();
        double t = (double)(ft-st)/CLOCKS_PER_SEC;
        out << n << endl << t << endl;
        if(t > 5.0) break;
    }

    return 0;
}