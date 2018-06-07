#include <bits/stdc++.h>
using namespace std;

class Solution {

    vector<double> sum;
    vector< vector<double> > dp;

    double avg(const int& i, const int& j){
        return ((i == 0) ? sum[j] : sum[j] - sum[i-1])/(double)(j-i+1);
    }

    double solve(const int& i, const int& n, const int& k, const vector<int>& a){
        double& ret = dp[i][k];
        if(ret == -1){

            if(i == n){
                ret = 0;
            } else if(k == 1){
                ret = avg(i, n-1);
            } else {
                double tmp = 0;
                for(int j = i; j < n; j++){
                    tmp = max(tmp, avg(i, j) + solve(j+1, n, k-1, a));
                }
                ret = tmp;
            }
        }
        return ret;
    }

public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        if(n == 0){
            return 0;
        } else if(n == 1){
            return A[0];
        }

        sum.resize(n);
        dp.resize(n+2, vector<double>(n+2, -1));
        sum[0] = A[0];
        for(int i = 1; i < n; i++){
            sum[i] = sum[i-1] + (double)A[i];
        }

        return solve(0, n, K, A);
    }
};