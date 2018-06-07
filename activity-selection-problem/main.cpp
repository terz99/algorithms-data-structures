#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int solve(pair<int, int> a[], const int& n){
    set<int> used;
    used.insert(0);
    int j = 0;

    for(int i = 1; i < n; i++){
        if(a[i].s >= a[j].f){
            used.insert(i);
            j = i;
        }
    }

    return used.size();
}

int main(){

    int cases;
    cin >> cases;
    vector<int> res;
    while(cases--){
        int n;
        cin >> n;
        pair<int, int> a[n+2];
        for(int i = 0; i < n; i++){
            cin >> a[i].s >> a[i].f;
        }
        sort(a, a+n);
        res.push_back(solve(a, n));
    }

    for(auto el : res){
        cout << el << endl;
    }

    return 0;
}