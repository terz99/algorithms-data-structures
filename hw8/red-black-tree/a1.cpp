#include <bits/stdc++.h>
using namespace std;

int main(){


    ofstream out("solution_a1.txt", ios::out);
    ifstream in("solution_a.txt", ios::in);
    
    map<string, bool> m;
    while(!in.eof()){
        string line;
        getline(in, line);
        if(!m[line]){
            m[line] = true;
            out << line << endl;
        }
    }
    
    out.close();
    in.close();

    return 0;
}