#include <bits/stdc++.h>
using namespace std;

struct Item{
    int sz, val;
};

int dp[2002][2002];

int solveRecursive(const int& n, const int& s, Item a[]){
    int& ret = dp[n][s];
    if(ret == -1){
        if(n == 0){
            ret = 0;
        } else {
            if(s - a[n-1].sz < 0){
                ret = solveRecursive(n-1, s, a);
            } else {
                ret = max(solveRecursive(n-1, s, a), solveRecursive(n-1, s - a[n-1].sz, a) + a[n-1].val);
            }
        }
    }
    return ret;
}

int solve(const int& n, const int& s, Item a[]){

    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= s; j++){
            if(a[i-1].sz > j){
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i-1].sz] + a[i-1].val);
            }
        }
    }
    return dp[n][s];
}

int main(){

    int s, n;
    cin >> s >> n;
    Item a[n+2];
    for(int i = 0; i < n; i++){
        cin >> a[i].sz >> a[i].val;
    }

    memset(dp, -1, sizeof(dp));
    cout << solveRecursive(n, s, a) << endl;
    // cout << solve(n, s, a) << endl;

    return 0;
}