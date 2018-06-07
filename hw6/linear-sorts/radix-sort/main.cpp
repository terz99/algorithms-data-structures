#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;

void counting_sort(int a[], int n, int m){

    vector<int> count(10, 0);
    vector<int> output(n);

    for(int i = 0; i < n; i++){
        count[ (a[i]/m)%10 ]++;
    }
    for(int i = 1; i < 10; i++){
        count[i] += count[i-1];
    }
    for(int i = 0; i < n; i++){
        output[ count[ (a[i]/m)%10 ]-1 ] = a[i];
        count[ (a[i]/m)%10 ]--;
    }

    for(int i = 0; i < n; i++){
        a[i] = output[i];
    }
}

void radixSort(int arr[], const int& n){
    int maxx = arr[0];
    for(int i = 1; i < n; i++){
        maxx = max(maxx, arr[i]);
    }
    int d = 0;
    while(maxx > 0){
        maxx /= 10;
        d++;
    }
    int m = 1;
    for(int i = 0; i < d; i++){
        counting_sort(arr, n, m);
        m *= 10;
    }
}

int main(){

    int n;
    cin >> n;
    int arr[n+2];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    radixSort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}