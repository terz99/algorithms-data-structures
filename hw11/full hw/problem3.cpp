/**
 * This is the solution for problem 3
 * @author Dushan Terzikj
 * @since 21.05.2018
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * Depth first search algorithm. Marks the current node as visited and checks 
 * for non-visited nodes to visit. Pushesh the node into a topological sort stack
 * at the end when all the neighbouring nodes are visited recursively.
 * @param curr the current node
 * @param vis[] vis[i] is true if node i is visited, false otherwise
 * @param s stack which is used for topological sorting
 * @param adj adjacency matrix.
*/
void dfs(const int& curr, bool vis[], stack<int>& s, const vector< vector<bool> >& adj){

    vis[curr] = true;
    for(unsigned int i = 0; i < adj[curr].size(); i++){
        if(adj[curr][i] && !vis[i]){
            dfs(i, vis, s, adj);
        }
    }
    s.push(curr);
}

/**
 * Topological sorting algorithm. Solution for the problem.
 * @param adj adjacency matrix
 * @return int[] nodes (students) topologically sorted and also in a row where i can pick on i+1 for i < n-1
s*/
vector<int> picking_order(const vector< vector<bool> >& adj){
    stack<int> s;
    int n = adj.size();
    bool vis[n];
    memset(vis, false, sizeof(vis));

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i, vis, s, adj);
        }
    }

    vector<int> res;
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    return res;
}

/**
 * Test driver function. If not desired, delete it or comment it out. Not for grading.
*/
int main(){

    int n;
    cin >> n;
    vector< vector<bool> > adj(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++){
        int to;
        cin >> to;
        adj[i][to] = true;
    }

    vector<int> res = picking_order(adj);
    for(auto el : res){
        cout << el << " ";
    }
    cout << endl;

    return 0;
}