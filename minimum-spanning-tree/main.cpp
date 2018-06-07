#include <bits/stdc++.h>
using namespace std;

class UnionFind{

    int n;
    int *id;
    int *rank;

public: 

    UnionFind(const int& n){
        this->n = n;
        id = new int[n];
        rank = new int[n];
        for(int i = 0; i < n; i++){
            id[i] = i;
            rank[i] = 1; 
        }
    }

    ~UnionFind(){
        delete[] id;
        delete[] rank;
    }

    int find(int x){
        while(x != id[x]){
            id[x] = id[id[x]];
            x = id[x];
        }
        return x;
    }

    bool connected(const int& x, const int& y){
        return find(x) == find(y);
    }

    void connect(const int& x, const int& y){

        int xRoot = find(x);
        int yRoot = find(y);
        if(rank[xRoot] > rank[yRoot]){
            id[yRoot] = xRoot;
        } else if(rank[yRoot] > rank[xRoot]){
            id[xRoot] = yRoot;
        } else {
            id[xRoot] = yRoot;
            rank[yRoot]++;
        }
    }
};

class Edge{
public: 
    int x, y, val;
    Edge(const int& x, const int& y, const int& val){
        this->x = x;
        this->y = y;
        this->val = val;
    }
    bool operator<(const Edge& e) const{
        return this->val < e.val;
    }
};

int solve(const int& n, const int& m, vector<Edge>& edges){

    sort(edges.begin(), edges.end());
    UnionFind uf(n);
    int ret = 0;
    for(int i = 0, treeSize = 1; i < m && treeSize < n; i++){

        Edge edge = edges[i];
        if(!uf.connected(edge.x, edge.y)){
            uf.connect(edge.x, edge.y);
            treeSize++;
            ret += edge.val;
        }
    }

    return ret;
}

int main(){

    int n, m;
    cin >> n >> m;
    vector<Edge> edges;

    for(int i = 0; i < m; i++){
        int from, to, val;
        cin >> from >> to >> val;
        edges.push_back(Edge(from, to, val));
    }

    cout << solve(n, m, edges) << endl;

    return 0;
}