#include <bits/stdc++.h>
using namespace std;

enum Color{WHITE, GREY, BLACK};
bool result = true;

void solve(const int& par, const int& node, const vector<int> edge[], Color color[]){

    color[node] = GREY;
    for(auto next : edge[node]){
        if(next == par){ 
            continue;
        } else if(color[next] == GREY && color[next] == BLACK){
            result = false;
            break;
        } else{ 
            solve(node, next, edge, color);
            if(!result) break;
        }
    }
    color[node] = BLACK;
}

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> edge[n+2];
    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        edge[from].push_back(to);
        edge[to].push_back(from);
    }

    if(n-1 != m){
        cout << "NO\n";
        return 0;
    }

    Color color[n+2];
    for(int i = 1; i <= n; i++) color[i] = WHITE;

    solve(0, 1, edge, color);
    for(int i = 1; i <= n; i++){
        if(color[i] != BLACK){
            result = false;
            break;
        }
    }

    if(result){
        cout << "YES\n"; 
    } else {
        cout << "NO\n";
    }

    return 0;
}