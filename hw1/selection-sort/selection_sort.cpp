/*
Author: Dushan Terzikj
Title: Selection Sort algorithm with STDIN 
*/

#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>& arr){

    // Selection sort algorithm

    int len = arr.size();
    for(int i = 0; i < len-1; i++){

        int min_val = arr[i];
        int min_idx = i;
        for(int j = i+1; j < len; j++){
            if(min_val > arr[j]){
                min_val = arr[j];
                min_idx = j;
            }
        }

        // swap
        int tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
    }
}

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    selection_sort(arr);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}