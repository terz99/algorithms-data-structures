/**
 * This is the solution for problem 2
 * @author Dushan Terzikj
 * @since 21.05.2018
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = (1 << 30); // a large int representing infinity

/**
 * Floyd-Warshall Algorithm. Dynamic programming algorithm used for finding shortest paths
 * between each pair of cities. Runs in O(n^3).
 * @param adj adjacency matrix for the edges between the nodes
 * @param p the starting city of one of the friend
 * @param q the starting city of the other friend
 * @return int - the optimal meeting city
 **/
int find_meetup_city(const std::vector< std::vector<int> >& adj, const int& p, const int& q){
    
    /* Setting initial values. Distance from one city to the same one is 0.
    dp[i][j] is INF if there is no edge between city i and city j. If there is an
    edge, then dp[i][j] is initially the weight of the edge */
    int n = adj.size();
    int dp[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) dp[i][j] = 0;
            else if(adj[i][j] != -1) dp[i][j] = adj[i][j];
            else dp[i][j] = INF;
        }
    }

    /* Floyd-Warshall algorithm */
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    /* Finding the optimal meeting city */
    int res = INF;
    int city;
    for(int i = 0; i < n; i++){
        if(res > std::max(dp[p][i], dp[q][i])){
            res = std::max(dp[p][i], dp[q][i]);
            city = i;
        }
    }
    return city;
}

/**
 * Main function used for testing. If you do not need it,
 * or just wish to use your own, either delete it or comment it
*/
int main(){

    int n, m;
    cin >> n >> m;
    vector< vector<int> > adj(n, vector<int>(n, -1));
    while(m--){
        int from, to, val;
        cin >> from >> to >> val;
        adj[from][to] = val;
        adj[to][from] = val;
    }
    int p, q;
    cin >> p >> q;
    cout << find_meetup_city(adj, p, q) << endl;

    return 0;
}

// Just a test case, don't mind this (dont grade it)
/*
8 12
0 3 3
0 2 4
0 1 1
2 3 2
2 4 2
1 4 10
3 4 3
4 5 10
5 6 2
7 6 11
4 7 5
4 6 1
0 6
*/