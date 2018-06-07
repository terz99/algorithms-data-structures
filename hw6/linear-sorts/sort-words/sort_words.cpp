/**
 * This program works with STDIN and STDOUT. It inputs N (number of words) and K the length of each word.
 * The words are stored in an array and then sorted alphabetically in O(n) time. The algorithm used
 * resembles bucket sort. I am using a linked list to store the words which start with the same letter.
 * @author Dushan Terzikj
 * @since 17.03.2018
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * This class represents a node(element) in the linked list
*/
class Node{
    public:
    string val;
    Node* next;
};

/**
 * This class represents a linked list. It has a starting element called 'start'
*/
class LinkedList{

    /**
     * This private method is used to insert a new string value into the linked list.
     * The strings in the linked list are sorted alphabetically.
     * @param curr the current node (initial call curr := start)
     * @param val the string to be added to the linked list 
    */
    void insert(Node *curr, string val){

        /* If the new string should be the first element in the linked list */
        if(curr->val > val){
            Node *newnode = new Node();
            newnode->val = curr->val; 
            newnode->next = curr->next;
            curr->val = val;
            curr->next = newnode;
            return;
        }

        /* All other cases */
        Node *prev = curr;
        while(curr != NULL && curr->val < val){
            prev = curr;
            curr = curr->next;
        }
        Node *newnode = new Node();
        newnode->val = val;
        newnode->next = curr;
        prev->next = newnode;
    }
    Node *start;

public:

    /* Constructors and destructors */

    LinkedList(){
        start = NULL;
    }

    ~LinkedList(){
        if(start != NULL){
            delete start;
        }
    }

    /* Service and helper methods */

    /**
     * This public method is used by the user to insert a new string into the linked list.
     * It calls the private insert method
     * @param val the string to be added
    */
    void insert(string val){
        /* If the start element of the linked list is NULL then assing the new element here */
        if(start == NULL){
            start = new Node();
            start->val = val;
            start->next = NULL;
        } else {
            insert(start, val);
        }
    }

    /**
     * This method is used to read the values in the linked list.
     * @param output an array of strings passed by reference. This is the 
     *               output where the strings are added.
    */
    void read(vector<string>& output){
        Node *curr = start;
        while(curr != NULL){
            output.push_back(curr->val);
            curr = curr->next;
        }
    }
};

/**
 * This function sorts a list of strings in alphabetical order. 
 * The algorithm resembles bucket-sort algorithm. It uses linked list
 * to store strings which start with the same letter.
 * @param a the list of strings to be sorted (passed by reference)
*/
void mysort(vector<string>& a){

    /* Make 26 linked lists (one for each letter) */
    LinkedList list[26];
    for(unsigned int i = 0; i < a.size(); i++){
        int idx = a[i][0]-'a'; // getting the index of the letter using its ASCII code
        list[idx].insert(a[i]);
    }

    /* Read the strings from the linked list (in which are sorted alphabetically for each
    individual letter) */
    vector<string> output;
    for(int i = 0; i < 26; i++){
        list[i].read(output);
    }
    a = output;
}

/**
 * Driver test method
*/
int main(){

    /* Input */
    int n;
    cin >> n;
    vector<string> a;
    int k;
    cin >> k;
    for(int i = 0; i < n; i++){
        string tmp = "";
        for(int j = 0; j < k; j++){
            char ch;
            cin >> ch;
            tmp = tmp + ch;
        }
        a.push_back(tmp);
    }

    /* Sort and output */

   mysort(a);

    for(int i = 0; i < n; i++){
        cout << a[i] << endl;
    }

    return 0;
}