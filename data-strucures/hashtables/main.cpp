#include <bits/stdc++.h>
using namespace std;

class Node{
public: 
    int key, value;
    Node* next;
};

class Hashtable{

    int MOD;
    Node** table;

    int hashFunction(int key){
        int ret = 0;
        while(key > 0){
            ret = ((ret*31 + key%10 + 13))%MOD;
            key /= 10;
        }
        return ret;
    }

public: 

    Hashtable(){
        MOD = 1000003;
        table = new Node*[MOD];
        for(int i = 0; i < MOD; i++){
            table[i] = NULL;
        }
    }

    Hashtable(const int& sz){
        MOD = sz;
        table = new Node*[sz];
        for(int i = 0; i < sz; i++){
            table[i] = NULL;
        }
    }

    void insert(const int& key, const int& value){
        int pos = hashFunction(key);
        if(!table[pos]){
            table[pos] = new Node();
            table[pos]->key = key;
            table[pos]->value = value;
            table[pos]->next = NULL;
        } else {
            Node* curr = table[pos];
            while(curr->key != key && curr->next) curr = curr->next;
            if(curr->key == key){
                curr->value = value;
                return;
            }
            curr->next = new Node();
            curr->next->key = key;
            curr->next->value = value;
            curr->next->next = NULL;
        }
    }

    int get(const int& key){
        int pos = hashFunction(key);
        if(!table[pos]){
            return -1;
        }
        Node* curr = table[pos];
        while(curr->key != key && curr) curr = curr->next;
        if(curr){
            return curr->value;
        } else {
            return -1;
        }
    }
};

int main(){

    Hashtable table;
    bool flag = true;
    while(flag){
        char op;
        cin >> op;
        int key, value;
        switch(op){
            case 'q': 
                flag = false;
                break;
            case 'a':
                cin >> key >> value;
                table.insert(key, value);
                break; 
            case 'g':
                cin >> key;
                value = table.get(key);
                cout << value << endl;
                break;
        }
    }

    return 0;
}