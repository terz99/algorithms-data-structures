/*
Title: Merge sort with randomized sequences, sizes and K
Author: Dushan Terzikj
Date: 18.02.2018

There is no need to execute this program again, because it is going to take a while
All the results are generated in files specified below. That data is then plotted using 
Matlab/Octave
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100000; /* Maximum size of a sequence */
const int TEST_CASES = 100; /* Number of test cases */ 

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

    srand(time(NULL));

    ofstream out;

    /* Randomized sequences. All the sequences are fixed size but the K varies */

    out.open("output.txt", ofstream::out);

    for(int t = 0; t < TEST_CASES; t++){

        int K = (t+1)*(MAX_SIZE/TEST_CASES);
        vector<int> arr;
        for(int i = 0; i < MAX_SIZE; i++){
            arr.push_back(rand()%INT_MAX);
        }

        clock_t start_time = clock();
        merge_sort(arr, 0, MAX_SIZE-1, K);
        clock_t end_time = clock();
        out << K << endl << (double)(end_time-start_time)/CLOCKS_PER_SEC << endl;
    }

    out.close();

    /* Best cases */

    out.open("best.txt", ofstream::out);

    for(int t = 0; t < TEST_CASES; t++){

        int K = (t+1)*(MAX_SIZE/TEST_CASES);
        vector<int> arr;
        for(int i = 0; i < MAX_SIZE; i++){
            arr.push_back(i);
        }

        clock_t start_time = clock();
        merge_sort(arr, 0, MAX_SIZE-1, K);
        clock_t end_time = clock();
        out << K << endl << (double)(end_time-start_time)/CLOCKS_PER_SEC << endl;
    }

    out.close();

    /* Worst case sequences */

    out.open("worst.txt", ofstream::out);

    for(int t = 0; t < TEST_CASES; t++){

        int K = (t+1)*(MAX_SIZE/TEST_CASES);
        vector<int> arr;
        for(int i = 0; i < MAX_SIZE; i++){
            arr.push_back(MAX_SIZE-i);
        }

        clock_t start_time = clock();
        merge_sort(arr, 0, MAX_SIZE-1, K);
        clock_t end_time = clock();
        out << K << endl << (double)(end_time-start_time)/CLOCKS_PER_SEC << endl;
    }

    out.close();

    return 0;
}