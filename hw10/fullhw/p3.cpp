/**
 * Problem 3
 * @author: Dushan Terzikj 30001357
 * @since: 29.04.2018
*/
#include <bits/stdc++.h>
using namespace std;

/* Big integer, representing infinity */
const int INF = (1 << 30);

/**
 * Struct which represents a cylinder
 * @param o is the amount of oxygen
 * @param n is the amount of nitrogen
 * @param w is the cylinder weight
*/
struct Cylinder{
    int o, n, w;
};

int main(){

    int cases;
    cin >> cases;
    while(cases--){

        /* Input and initialization */
        int N, O, n;
        cin >> O >> N >> n;
        Cylinder arr[n+2];
        for(int i = 0; i < n; i++){
            cin >> arr[i].o >> arr[i].n >> arr[i].w;
        }

        int dp[n+2][O+2][N+2];
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= O; j++){
                for(int k = 0; k <= N; k++){
                    dp[i][j][k] = ((j == 0 && k == 0) ? 0 : INF);
                }
            }
        }

        for(int j = 0; j <= O; j++){
            for(int k = 0; k <= N; k++){
                if(j <= arr[0].o && k <= arr[0].n && (j > 0 || k > 0)){
                    dp[0][j][k] = arr[0].w;
                }
            }
        }

        /* Dynamic programming algorithm */
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= O; j++){
                for(int k = 0; k <= N; k++){
                    dp[i][j][k] = dp[i-1][j][k];
                    if(j <= arr[i].o && k <= arr[i].n){
                        dp[i][j][k] = min(dp[i][j][k], arr[i].w);
                    } else {
                        int J = max(0, j-arr[i].o);
                        int K = max(0, k-arr[i].n);
                        if(dp[i][j][k] > arr[i].w + dp[i-1][J][K]){
                            dp[i][j][k] = arr[i].w + dp[i-1][J][K];
                        }
                    }
                }
            }
        }

        /* Path reconstruction */
        int i = n-1, currO = O, currN = N;
        vector<int> seq;
        while(i >= 0 && (currO > 0 || currN > 0)){
            if(i == 0){
                seq.push_back(i+1);
                break;
            } else if(dp[i][currO][currN] != dp[i-1][currO][currN]){
                currO -= arr[i].o; currO = max(currO, 0);
                currN -= arr[i].n; currN = max(currN, 0);
                seq.push_back(i+1);
                i--;
            } else {
                i--;
            }
        }
        reverse(seq.begin(), seq.end());

        /* Output */
        cout << dp[n-1][O][N] << endl;
        for(auto el : seq){
            cout << el << " "; 
        }
        cout << endl;
    }

    return 0;
}