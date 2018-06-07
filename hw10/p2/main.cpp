/**
 * Problem 2
 * @author: Dushan Terzikj 30001357
 * @since: 29.04.2018
*/
#include <bits/stdc++.h>
#include "algorithm.h"
using namespace std;

/**
 * Driver test program to test the algorithm which is contained
 * in 'algorithm.h'
*/
int main(){

    /* Input */
    int n;
    cin >> n;
    vector< vector<int> > mat(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin >> mat[i][j];
        }
    }

    /* Algorithm */
    Solution sol(n, mat);
    sol.solve();
    Result res = sol.getResult();

    /* Output */
    cout << res.res << endl;
    for(unsigned int i = 0; i < res.seq.size(); i++){
        cout << res.seq[i] << " ";
    }
    cout << endl;

    return 0;
}