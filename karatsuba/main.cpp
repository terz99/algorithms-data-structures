#include <bits/stdc++.h>
using namespace std;

/* Converts a decimal integer to binary */
string to_binary(int x){

    if(x == 0){
        return "0";
    }

    string ret;
    while(x > 0){
        ret = (char)((x%2)+'0') + ret;
        x /= 2;
    }

    return ret;
}

int make_same_length(string& a, string& b){

    /* Takes two strings @param a and @param b and makes them the same length
    by adding 0s to the left of the smaller string 
    Returns the length */

    if(a.length() == b.length()){
        return (int)a.length();
    }

    while(a.length() < b.length()){
        a = "0" + a;
    }
    while(b.length() < a.length()){
        b = "0" + b;
    }
    return (int)a.length();
}

/* Multiplies bits of length 1 */
int multiply_single_bit(string a, string b){
    return (int)(a[0]-'0')*(b[0]-'0');
}

/* Adds two binary numbers */
string add_bit_strings(string a, string b){

    int n = make_same_length(a, b);
    int carry = 0;
    string ret;
    for(int i = n-1; i >= 0; i--){

        int first_bit = (int)(a[i]-'0');
        int second_bit = (int)(b[i]-'0');

        int sum = (first_bit ^ second_bit ^ carry) + '0';

        ret = (char)sum + ret;

        carry = (first_bit & second_bit) | (first_bit & carry) | (second_bit & carry);
    }

    if(carry){
        ret = "1" + ret;
    }
    return ret;
}

int multiply(string a, string b){

    /* Multiplies two binary strings using Karatsuba D&C algorithm */

    int n = make_same_length(a, b);

    if(n == 0){
        return 0;
    }
    if(n == 1){
        return multiply_single_bit(a, b);
    }

    int mid = n/2;
    int sh = n-mid;

    /* Dividing the string into left and right parts */
    string al = a.substr(0, mid);
    string ar = a.substr(mid);
    string bl = b.substr(0, mid);
    string br = b.substr(mid);

    /* terms of Karatsuba algorithm */
    int t1 = multiply(al, bl);
    int t2 = multiply(ar, br);
    int t3 = multiply(add_bit_strings(al, ar), add_bit_strings(bl, br));

    return t1*(1 << (2*sh)) + (t3 - t1 - t2)*(1 << sh) + t2;
}

int main(){

    while(true){

        int a, b;
        cout << "Enter two numbers (0s if you want to quit):\n";
        cin >> a >> b;

        if(a == 0 && b == 0){
            break;
        }
        string bin_a = to_binary(a);
        string bin_b = to_binary(b);
        cout << multiply(bin_a, bin_b) << endl;
    }

    return 0;
}