#include <bits/stdc++.h>
using namespace std;

inline int max3(const int& a, const int& b, const int& c){ return max(a, max(b, c)); }

int max_crossing_sum(const vector<int>& a, const int& l, const int& mid, const int& r){

    int left_sum, right_sum, sum;
    left_sum = right_sum = INT_MIN;
    sum = 0;
    for(int i = mid; i >= l; i--){
        sum += a[i];
        left_sum = max(left_sum, sum);
    }

    sum = 0;
    for(int i = mid+1; i <= r; i++){
        sum += a[i];
        right_sum = max(right_sum, sum);
    }

    return left_sum + right_sum;
}

int max_subarray_sum(const vector<int>& a, const int& l, const int& r){

    if(l == r){
        return a[l];
    }

    int mid = (l+r)/2;
    return max3(max_subarray_sum(a, l, mid), max_subarray_sum(a, mid+1, r), max_crossing_sum(a, l, mid, r));
}

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << max_subarray_sum(a, 0, a.size()-1) << endl;

    return 0;
}