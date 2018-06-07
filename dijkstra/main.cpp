#include <bits/stdc++.h>
using namespace std;

#define NOT_REACHED -1
#define d second
#define node first

int dijkstra(const int& n, const vector< pair<int, long long> > edges[], const int& s, const int& f){
    
    long long d[n+2];
    for(int i = 1; i <= n; i++){
        d[i] = NOT_REACHED;
    }
    
    priority_queue< pair<long long, int>, vector< pair<long long, int> >, greater< pair<long long, int> > > q;
    q.push(make_pair(0, s));
    while(!q.empty()){
        long long dist = q.top().first;
        int curr = q.top().second;
        q.pop();
        if(d[curr] != NOT_REACHED) continue;
        d[curr] = dist;
        for(auto edge : edges[curr]){
            if(d[edge.node] == NOT_REACHED){
                q.push(make_pair(edge.d + dist, edge.node));
            }
        }
    }
    return d[f];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cases;
    cin >> cases;
    while(cases--){
        int n, m;
        cin >> n >> m;
        vector< pair<int, long long> > edges[n+2];
        while(m--){
            int from, to;
            long long val;
            cin >> from >> to >> val;
            edges[from].push_back(make_pair(to, val));
        }
        int source, end;
        cin >> source >> end;
        long long res = dijkstra(n, edges, source, end);
        if(res == -1) cout << "NO\n";
        else cout << res << endl;
    }

    return 0;
}