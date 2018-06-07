#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>& arr){

    for(int i = 1; i < (int)arr.size(); i++){

        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key; 
    }
}

int main(){

    vector<int> arr;
    for(int i = 0;; i++){
        cout << "Enter a number (negative to stop streaming): ";
        int tmp; 
        cin >> tmp;
        if(tmp < 0){
            break;
        } else {
            arr.push_back(tmp);
        }
    }

    insertion_sort(arr);

    for(int i = 0; i < (int)arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}