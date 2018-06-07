#include <bits/stdc++.h>
using namespace std;

int heapSize;

void xchg(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

void maxHeapify(int arr[], const int& i){
    int l = 2*i+1;
    int r = l+1;
    int largest;
    if(l < heapSize && arr[l] > arr[i]){
        largest = l;
    } else {
        largest = i;
    }
    if(r < heapSize && arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != i){
        xchg(arr[i], arr[largest]);
        maxHeapify(arr, largest);
    }
}

void buildMaxHeap(int arr[], const int& n){
    heapSize = n;
    for(int i = n/2; i >= 0; i--){
        maxHeapify(arr, i);
    }
}

void heapSort(int arr[], const int& n){

    buildMaxHeap(arr, n);
    for(int i = n-1; i > 0; i--){
        xchg(arr[0], arr[i]);
        heapSize--;
        maxHeapify(arr, 0);
    }
}

int main(){

    int n;
    cin >> n;
    int arr[n+2];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    heapSort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}