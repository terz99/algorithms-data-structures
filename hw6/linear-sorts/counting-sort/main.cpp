#include <bits/stdc++.h>
using namespace std;

void countingSort(int a[], const int& n){
    int b[n+2];
    int range = a[0];
    for(int i = 1; i < n; i++){
        range = max(range, a[i]);
    }
    int c[range+2];
    memset(c, 0, sizeof(c));
    for(int i = 0; i < n; i++){
        c[a[i]]++;
    }
    for(int i = 1; i <= range; i++){
        c[i] = c[i] + c[i-1];
    }
    for(int i = 0; i < n; i++){
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }
    for(int i = 0; i < n; i++){
        a[i] = b[i+1];
    }
}

int main(){

    int n;
    cin >> n;
    int arr[n+2];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    countingSort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}