/**
 * Problem 1
 * @author: Dushan Terzikj 30001357
 * @since: 29.04.2018
*/
#include <bits/stdc++.h>
using namespace std;

int *dp;

/**
 * The algorithm for getting the longest increasing
 * subsequence.
 * @param arr the full sequence
 * @param n the size of the full sequence (arr)
*/
int solve(int arr[], int n){

    for(int i = 0; i < n; i++){
        /* Each number is a increasing subsequence of length 1 with itself */
        dp[i] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] && dp[i] < dp[j]+1){
                dp[i] = dp[j] + 1;
            }
        }
    }

    /* Getting the biggest result, i.e., the longest increasing subsequence */
    int res = 0;
    for(int i = 0; i < n; i++){
        res = max(res, dp[i]);
    }
    return res;
}

int main(){

    /* Input an initialization */
    int n;
    cin >> n;
    int arr[n+2];

    dp = new int[n+2];

    int longest = solve(arr, n); // call the algorithm
    
    /* Path reconstruction */
    int lastPos = longest;
    vector<int> seq(longest, -1);
    for(int i = n-1; i >= 0; i--){
        if(lastPos == dp[i] && arr[i] > seq[lastPos-1]){
            if(lastPos == longest){
                seq[lastPos-1] = arr[i];
            } else if(arr[i] < seq[lastPos]){
                seq[lastPos-1] = arr[i];
            }
        } else if(lastPos-1 == dp[i]){
            lastPos--;
            seq[lastPos-1] = arr[i];
        }
    }

    /* Output */
    for(unsigned int i = 0; i < seq.size(); i++){
        cout << seq[i] << " ";
    }
    cout << endl;

    delete[] dp; // Memory dealloc

    return 0;
}