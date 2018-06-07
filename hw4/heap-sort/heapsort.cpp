/**
 * This is an implementation of heap sort. It uses STDIN and STDOUT
 * 
 * @author Dushan Terzikj (30001357)
 * @since 04.03.2018 
*/
#include <bits/stdc++.h>
using namespace std;

/* Global variable used to store the size of the heap */
int heap_size;

/**
 * Function which restores the max-heap principle of the heap array.
 * In other words starts at *root* checks if it is smaller than any of its children.
 * If so, then it swaps the values with the bigger child and calls max_heapify() on that child
 * 
 * @param arr the heap array
 * @param root the current root of the tree/subtree
*/
void max_heapify(vector<int>& arr, const int& root){

    /* Get left and right child */
    int left = (root << 1);
    int right = left | 1;
    /* Index of the largest child */
    int max_idx;
    if(left < heap_size && arr[left] > arr[root]){
        /* If the left child is bigger than the root, assign left to the max_idx */
        max_idx = left;
    } else {
        /* Otherwise, store the default to be the root (assume that root is bigger than both children) */
        max_idx = root;
    }

    if(right < heap_size && arr[right] > arr[max_idx]){
        /* If rigth child is bigger than the current biggest node (might be root or left child) assigne right to the max_idx */
        max_idx = right;
    }

    if(max_idx != root){
        /* If the greatest value is not in the root, then we need to swap the root with
        one if its children and max_heapify() that child */
        int tmp = arr[root];
        arr[root] = arr[max_idx];
        arr[max_idx] = tmp;
        max_heapify(arr, max_idx);
    }
}

/**
 * Function that builds the heap array. It starts from the lowest nodes that are NOT leaves.
 * Calls max_heapify on each of them.
 * @param arr the heap array
*/
void build_max_heap(vector<int>& arr){

    heap_size = arr.size();
    for(int i = arr.size()/2 - 1; i >= 0; i--){
        max_heapify(arr, i);
    }
}

/**
 * Sorting algorithm which uses max-heap data structure.
 * First builds the array as a heap and then takes the largest element
 * from the root of the heap and places into a sorted_array starting from the end.
 * It repeats these steps until the heap is empty.
 * 
 * @param arr the array to be sorted
*/
void heap_sort(vector<int>& arr){

    build_max_heap(arr);

    for(int i = arr.size()-1; i >= 1; i--){
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heap_size--;
        max_heapify(arr, 0);
    }
}

int main(){

    /* Input */
    int array_size;
    cin >> array_size;
    vector<int> arr(array_size);

    for(int i = 0; i < array_size; i++){
        cin >> arr[i];
    }

    /* Heap sort and output */
    heap_sort(arr);
    for(int i = 0; i < array_size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}