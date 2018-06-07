#include <bits/stdc++.h>
using namespace std;

void xchg(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(int arr[], const int& p, const int& r){
    int piv = p;
    int i = p;
    for(int j = p+1; j <= r; j++){
        if(arr[j] < arr[piv]){
            i++;
            xchg(arr[j], arr[i]);
        }
    }
    xchg(arr[piv], arr[i]);
    return i;
}

int randomizedPartition(int arr[], const int& p, const int& r){
    int piv = (rand()%(r-p+1))+p;
    xchg(arr[piv], arr[p]);
    return partition(arr, p, r);
}

void quicksort(int arr[], const int& p, const int& r){
    if(p < r){
        int piv = randomizedPartition(arr, p, r);
        quicksort(arr, p, piv-1);
        quicksort(arr, piv+1, r);
    }
}

int main(){

    srand(time(NULL));

    int n;
    cin >> n;
    int arr[n+2];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    quicksort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}