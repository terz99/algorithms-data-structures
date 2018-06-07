/**
 * This program represents 3-way quicksort. It uses two pivots (the first and the second element of the array to be sorted).
 * @author Dushan Terzikj
 * @since 11.03.2018
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * Swapping function
 * @param a
 * @param b 
*/
void myswap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

/**
 * Dual pivot partition. It uses the first two elements as pivot.
 * @param arr the array that needs to be sorted
 * @param start the start of the current partition
 * @param end the end of the current partition
 * @ param l_pivot_idx is the index of the left (smaller) pivot. It is passed by
 * reference because it is used in quicksort()
 * @param r_pivot_idx is the index of the right (greater) pivot. It is passed by
 * reference because it is used in quicksort()  
*/
void mypartition(vector<int>& arr, int start, int end, int& l_pivot_idx, int& r_pivot_idx){

    /* Instead of making the right index and left index next to each other
    I swap the second element and the end element. Then I set the left pivot 
    to be the smaller element and right pivot to be the greater element.
    Left index is start + 1 and right index is end - 1 (since i swapped the end and 
    (start+1) element, technically i am still using the first two elements). */
    myswap(arr[start+1], arr[end]);
    if(arr[start] > arr[end]){
        myswap(arr[start], arr[end]);
    }

    int l_pivot = arr[start];
    int r_pivot = arr[end];
    int l_idx = start + 1;
    int r_idx = end - 1;
    int idx = start + 1;
    while(idx <= r_idx){

        /* Put all elements smaller than the left(smaller) pivot to the left */
        if(arr[idx] < l_pivot){
            myswap(arr[idx], arr[l_idx]);
            l_idx++;
        } else if(arr[idx] >= r_pivot){ /* Put all elements greater than the right(greater) pivot to the right */

            while(arr[r_idx] > r_pivot && idx < r_idx){
                r_idx--;
            }
            myswap(arr[idx], arr[r_idx]);
            r_idx--;

            /* Check if the new swapped element is less than the left pivot. If so, take it to the left side */
            if(arr[idx] < l_pivot){
                myswap(arr[idx], arr[l_idx]);
                l_idx++;
            }
        }
        /* All the elements between the left and right pivot go in the middle section */
        idx++;
    }

    /* Assign the pivots and use them in quicksort() for further partition */
    l_idx--;
    r_idx++;

    myswap(arr[start], arr[l_idx]);
    myswap(arr[end], arr[r_idx]);

    l_pivot_idx = l_idx;
    r_pivot_idx = r_idx;
}

/**
 * Quicksort algorithm with two pivots. It puts the elements smaller than the left(smaller) pivot to the left,
 * elements greater than the right(greater) pivot to the right and all the rest in the middle subarray
*/
void quicksort(vector<int>& arr, int start, int end){

    if(start < end){

        int l_pivot_idx, r_pivot_idx;
        mypartition(arr, start, end, l_pivot_idx, r_pivot_idx);
        quicksort(arr, start, l_pivot_idx-1);
        quicksort(arr, l_pivot_idx+1, r_pivot_idx-1);
        quicksort(arr, r_pivot_idx+1, end);
    }
}

int main(){

    /* Input */
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    /* Sort and output */
    quicksort(a, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}