#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<float>& a){
    int n = a.size();
    vector<float> b[n+2];
    for(int i = 0; i < n; i++){
        b[(int)a[i]*n].push_back(a[i]);
    } 
    for(int i = 0; i < n; i++){
        sort(b[i].begin(), b[i].end());
    }
    a.clear();
    for(int i = 0; i < n; i++){
        for(unsigned int j = 0; j < b[i].size(); j++){
            a.push_back(b[i][j]);
        }
    }
}

int main(){

    int n;
    cin >> n;
    vector<float> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    bucketSort(a);

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}