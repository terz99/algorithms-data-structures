/**
 * Problem 2
 * @author: Dushan Terzikj 30001357
 * @since: 29.04.2018
*/
#include <bits/stdc++.h>

#ifndef _ALGORITHM_H
#define _ALGORITHM_H

/**
 * This class represents the result of the problem.
 * @param seq a vector which contains the path of the result
 * @param res the result
*/
class Result{
public:
    std::vector<int> seq;
    int res;
    Result(const int& res, const std::vector<int>& seq){
        this->res = res;
        this->seq = seq;
    }
};

/**
 * A class which contains member variables and methods needed
 * for the algorithm implementation
 * @param n 
 * @param mat 
 * @param seq the path of the result
 * @param res the result
*/
class Solution{

    int n;
    std::vector< std::vector<int> > mat;
    std::vector<int> seq;
    int res;

    /**
     * Recursive bruteforce method
     * @param i
     * @param j
    */
    int solveBruteforceUtil(const int& i, const int& j){
        if(i == n-1){
            return mat[i][j];
        }
        return std::max(solveBruteforceUtil(i+1, j), solveBruteforceUtil(i+1, j+1)) + mat[i][j];
    }

public:

    /**
     * Public method. Contains the implementation
     * of the dynamic programming algorithm
    */
    void solve(){

        /* Algorithm */
        std::vector< std::vector<int> > dp(n, std::vector<int>(n, -1));
        std::vector< std::vector<int> > p(n, std::vector<int>(n, -1)); // used to store the predecessor for path reconstruction
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                if(i == 0){
                    dp[i][j] = mat[i][j];
                } else {
                    int topLeft = ((j == 0) ? 0 : dp[i-1][j-1]);
                    int topRight = ((j == i) ? 0 : dp[i-1][j]);
                    if(dp[i][j] < std::max(topLeft, topRight) + mat[i][j]){
                        dp[i][j] = std::max(topLeft, topRight) + mat[i][j];
                        if(topLeft >= topRight){
                            p[i][j] = (i-1)*n+j-1;
                        } else {
                            p[i][j] = (i-1)*n+j;
                        }
                    }
                }
            }
        }

        /* Finding maximum */
        res = INT_MIN;
        int sx, sy;
        for(int i = 0; i < n; i++){
            if(res < dp[n-1][i]){
                res = dp[n-1][i];
                sx = n-1;
                sy = i;
            }
        }

        /* Backtracking for path reconstruction */
        while(sx != -1 && sy != -1){
            seq.push_back(mat[sx][sy]);
            int nx = p[sx][sy]/n;
            int ny = p[sx][sy]%n;
            sx = nx;
            sy = ny;
        }
        reverse(seq.begin(), seq.end()); // reverse, since we get a reversed sequence
        // from bottom to top
    }

    /**
     * Public brute force method. Calls private solveBruteForceUtil()
     * which is a recursive method
    */
    void solveBruteforce(){
        res = solveBruteforceUtil(0, 0);
    }

    /**
     * Default constructor.
     * @param n
     * @param mat
    */
    Solution(const int& n, const std::vector< std::vector<int> >& mat){
        this->n = n;
        this->mat = mat;
    }

    /**
     * A getter for the result
     * @return Result
    */
    Result getResult(){
        return Result(res, seq);
    }
};

#endif // !_ALGORITHM_H