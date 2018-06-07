#include <bits/stdc++.h>
using namespace std;

void multiply(vector< vector<int> >& A, vector< vector<int> >& B, vector< vector<int> >& C){
    
}

int main(){

    int n;
    cout << "Enter the size of the matrices: ";
    cin >> n;
    vector< vector<int> > A(n, vector<int>(n)), B(n, vector<int>(n)), C(n, vector<int>(n));

    cout << "Enter first matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }

    cout << "Enter second matrix\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> B[i][j];
        }
    }

    multiply(A, B, C);

    return 0;
}