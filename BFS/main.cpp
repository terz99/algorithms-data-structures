#include <bits/stdc++.h>
using namespace std;

#define NOT_REACHED -1

void bfs(const int& source, const int& n, const vector<int> edge[], int d[]){

    for(int i = 1; i <= n; i++){
        d[i] = NOT_REACHED;
    }

    d[source] = 0;
    queue<int> q;
    q.push(source);
    while(!q.empty()){

        int curr = q.front();
        q.pop();

        for(auto next : edge[curr]){
            if(d[next] == -1){
                d[next] = d[curr] + 1;
                q.push(next);
            }
        }
    }
}

int solve(const int& n, const vector<int> edge[]){
    
    int d[n+2];
    bfs(1, n, edge, d);
    int maxx, node;
    maxx = 0;
    node = 1;
    for(int i = 1; i <= n; i++){
        if(d[i] > maxx){
            maxx = d[i];
            node = i;
        }
    }
    bfs(node, n, edge, d);
    maxx = 0;
    for(int i = 1; i <= n; i++){
        maxx = max(maxx, d[i]);
    }
    return maxx;
}

int main(){

    int n;
    cin >> n;
    vector<int> edge[n+2];
    for(int i = 0; i < n-1; i++){
        int from, to;
        cin >> from >> to;
        edge[from].push_back(to);
        edge[to].push_back(from);
    }

    cout << solve(n, edge) << endl;

    return 0;
}