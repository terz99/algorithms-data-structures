#include <bits/stdc++.h>
using namespace std;

#define MAX 50002

int readline(char *str){

    int i = 0;
    char ch;
    while((ch = getchar()) != '\n'){
        str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

int solve(char *x, char *y, const int& lx, const int& ly, int dp[][MAX]){

    int now = 0;
    for(int i = 1; i <= lx; i++){
        int prev = now;
        now = now^1;
        for(int j = 1; j <= ly; j++){
            if(x[i-1] == y[j-1]){
                dp[now][j] = dp[prev][j-1] + 1; 
            } else {
                dp[now][j] = max(dp[now][j-1], dp[prev][j]);
            }
        }
    }
    return dp[now][ly];
}

int main(){

    char x[MAX], y[MAX];

    int lx = readline(x);
    int ly = readline(y);

    int dp[2][MAX];

    cout << solve(x, y, lx, ly, dp) << endl;

    return 0;
}