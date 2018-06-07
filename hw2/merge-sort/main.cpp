/*
Title: Merge sort with STDIN and STDOUT
Author: Dushan Terzikj
Date: 18.02.2018

This program can be executed with the command 'g++ main.cpp' and then running './a.out' 
You will need to type the number of elements first, then the elements themselves. After that
You would need to insert K. 
*/
#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>& arr, int start, int end){

    /* Insertion sort algorithm */

    for(int i = start+1; i <= end; i++){

        int key = arr[i];
        int j = i-1;
        while(j >= start && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void my_merge(vector<int>& arr, int start, int mid, int end){

    /* This method merges the left and right array */

    vector<int> ls;
    vector<int> rs;
    for(int i = start; i <= mid; i++){
        ls.push_back(arr[i]);
    }
    for(int i = mid+1; i <= end; i++){
        rs.push_back(arr[i]);
    }

    int i = 0, j = 0, k = start;
    while(i < (int)ls.size() && j < (int)rs.size()){
        if(ls[i] < rs[j]){
            arr[k++] = ls[i++];
        } else {
            arr[k++] = rs[j++];
        }
    }

    /* Adding leftover elements from either the left or right array 
    I did not use INFINITY as the last element, because I like this method better,
    it is still correct */
    while(i < (int)ls.size()){
        arr[k++] = ls[i++];
    }
    while(j < (int)rs.size()){
        arr[k++] = rs[j++];
    }
}

void merge_sort(vector<int>& arr, int start, int end, int K){

    /* Merge sort algorithm */

    if(end - start + 1 <= K){
        insertion_sort(arr, start, end);
        return;
    }

    int mid = (start + end)/2;
    merge_sort(arr, start, mid, K);
    merge_sort(arr, mid+1, end, K);
    my_merge(arr, start, mid, end);
}

int main(){

    int num_elements;
    cin >> num_elements;
    vector<int> arr(num_elements);
    for(int i = 0; i < num_elements; i++){
        cin >> arr[i];
    }

    /* Constant, size of the smallest array which needs to be divided */
    int K;
    cin >> K;

    merge_sort(arr, 0, num_elements-1, K);

    for(int i = 0; i < num_elements; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}