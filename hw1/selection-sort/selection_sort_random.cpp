/*
Author: Dushan Terzikj
Title: Selection Sort on Randomized, Best case and Worst case Sequences
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

    // set the seed for rand() function
    srand(time(NULL));
    ofstream out;
    // results from random sequences are stored in output.txt
    out.open("output.txt", ofstream::out);

    // next 5 lines of code generate the sizes of the arrays
    // the MAX_SIZE and TEST_CASES are set arbitrarily
    // and with lower value for the sake of run-time execution
    int MAX_SIZE = 152000;
    int TEST_CASES = 50;
    vector<int> sizes;
    for(int i = 1; i <= TEST_CASES; i++){
        sizes.push_back(i*(MAX_SIZE/TEST_CASES));
    }
    
    // Generating random sequences and then sorting them
    for(int i = 0; i < (int)sizes.size(); i++){
        int curr_size = sizes[i];
        vector<int> arr(curr_size);
        out << curr_size << endl;
        for(int i = 0; i < curr_size; i++){
            arr[i] = rand()%INT_MAX;
        }
        clock_t start_time = clock();
        selection_sort(arr);
        clock_t end_time = clock();
        out << (double)(end_time-start_time)/CLOCKS_PER_SEC << endl;
    }

    out.close();

    // Generating best cases (already sorted arrays) 
    // and then sorting them
    out.open("best_cases.txt", ofstream::out);
    for(int i = 0; i < (int)sizes.size(); i++){
        int curr_size = sizes[i];
        vector<int> arr(curr_size);
        out << curr_size << endl;
        for(int i = 0; i < curr_size; i++){
            arr[i] = i;
        }
        clock_t start_time = clock();
        selection_sort(arr);
        clock_t end_time = clock();
        out << (double)(end_time - start_time)/CLOCKS_PER_SEC << endl;
    }
    out.close();

    // Generating worst cases (decreasing order sorted array)
    // and then sorting them in increasing order
    out.open("worst_cases.txt", ofstream::out);
    for(int i = 0; i < (int)sizes.size(); i++){
        int curr_size = sizes[i];
        vector<int> arr(curr_size);
        out << curr_size << endl;
        for(int i = 0; i < curr_size; i++){
            arr[i] = curr_size-i;
        }
        clock_t start_time = clock();
        selection_sort(arr);
        clock_t end_time = clock();
        out << (double)(end_time - start_time)/CLOCKS_PER_SEC << endl;
    }
    out.close();


    return 0;
}