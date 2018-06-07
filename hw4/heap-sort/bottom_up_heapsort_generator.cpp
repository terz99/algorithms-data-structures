/**
 * This is an implementation of bottom up heap sort. It generates random sequences as input
 * and writes the runtime in 'bottom_up_heapsort.txt'
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
 * This is a bottom-way approach. In other words, it traverses the trees in a way
 * that chooses the child node which is larger. If the current root node is greater
 * than the largest child or if its on a leaf level, the traversal stops. After it 
 * stops it pushesh the nodes in the traversed path for one level up, therefore
 * restoring the heap structure
 * 
 * @param arr the heap array
 * @param root the current root of the subtree
*/
void bottom_up(vector<int>& arr, const int& root){

    /* Get left and right child */
    int left = 2*root + 1;
    int right = left + 1;
    /* Index of the root of the tree */
    int max_idx = 0;
    if(left < heap_size && arr[left] > arr[max_idx]){
        /* If the left child is the largest child, choose that path */
        max_idx = left;
    }
    if(right < heap_size && arr[right] > arr[max_idx]){
        /* If the right child is the largest, choose that path */
        max_idx = right;
    }

    if(max_idx == 0){
        /* If the current node is either a leaf or its children is less than the root */
        int tmp = arr[0];
        arr[0] = arr[root];
        arr[root] = tmp;
        return;
    }

    bottom_up(arr, max_idx);
    int tmp = arr[0];
    arr[0] = arr[root];
    arr[root] = tmp;
}

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
    int left = 2*root + 1;
    int right = left + 1;
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
        bottom_up(arr, 0);
    }
}

int main(){

    srand(time(NULL));

    ofstream out;
    out.open("bottom_up_heapsort.txt", ofstream::out);
    out.precision(6);

    const int TEST_CASES = 100;
    const int MAX_SIZE = 17000000;

    for(int k = 1; k <= TEST_CASES; k++){

        int curr_size = k*(MAX_SIZE/TEST_CASES);
        vector<int> arr;

        /* Random cases */
        for(int i = 0; i < curr_size; i++){
            arr.push_back(rand()%INT_MAX);
        }

        clock_t start_time = clock();
        heap_sort(arr);
        clock_t end_time = clock();
        out << curr_size << endl << (double)(end_time - start_time)/CLOCKS_PER_SEC << endl;
        arr.clear();

        /* Worst cases */
        for(int i = 0; i < curr_size; i++){
            arr.push_back(i);
        }

        start_time = clock();
        heap_sort(arr);
        end_time = clock();
        out << curr_size << endl << (double)(end_time - start_time)/CLOCKS_PER_SEC << endl;
        arr.clear();

        /* Best cases */
        for(int i = 0; i < curr_size; i++){
            arr.push_back(curr_size-i);
        }

        start_time = clock();
        heap_sort(arr);
        end_time = clock();
        out << curr_size << endl << (double)(end_time - start_time)/CLOCKS_PER_SEC << endl;
    }

    out.close();

    return 0;
}