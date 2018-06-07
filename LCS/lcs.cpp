#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int lcs(const string& x, const int& i, const string& y, const int& j){
    if(dp[i][j] == -1){
        if(i == 0 || j == 0){
            dp[i][j] = 0;
        } else if(x[i-1] == y[j-1]){
            dp[i][j] = 1 + lcs(x, i-1, y, j-1);
        } else {
            dp[i][j] = max(lcs(x, i-1, y, j), lcs(x, i, y, j-1));
        }
    }
    return dp[i][j];
}

int main(){

    memset(dp, -1, sizeof(dp));
    string x = "AGGTAB";
    string y = "GXTXAYB";
    lcs(x, x.length(), y, y.length());
    string seq = "";
    int i = x.length();
    int j = y.length();
    while(i > 0 && j > 0){
        if(x[i-1] == y[j-1]){
            seq = x[i-1] + seq;
            i--;
            j--;
        } else {
            j--;
        }
    }
    cout << seq << endl;

    return 0;
}