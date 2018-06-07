#ifndef _STACK_H
#define _STACK_H

#include <bits/stdc++.h>
using namespace std;

/**
 * This class represents a generic Stack class. Uses a linked list
 * for implementation.
 * @author Dushan Terzikj
 * @since 03.04.2018
*/
template<class T>
class Stack{

    private:

    const string underflowException = "underflow";
    const string overflowException = "overflow";

    class StackNode{

        public: 
        T data;
        StackNode *next;
        StackNode(){}
        StackNode(T data){
            this->data = data;
            this->next = NULL;
        }
    };

    StackNode *top;
    int size;
    int currSize;

    public:

    /**
     * Default constructor. Sets {@code top} to {@code NULL}
     * {@code size} to -1 and {@code currSize} to 0
    */
    Stack(){
        this->top = NULL;
        this->size = -1;
        this->currSize = 0;
    }

    /**
     * Parametrized constructor. Sets {@code top} to {@code NULL}
     * {@code this->size} to {@code size} and {@code currSize} to 0
     * @param size the size of the Stack
    */
    Stack(const int& size){
        this->top = NULL;
        this->size = size;
        this->currSize = 0;
    }

    /**
     * Pushes a new element into the Stack. 
     * @param elem
     * @throws overflow exception
    */
    void push(const T& elem){

        try{
            if(this->currSize == this->size){
                throw overflowException;
            }
            if(this->top == NULL){
                this->top = new StackNode(elem);
                this->currSize++;
                return;
            }

            StackNode *newnode = new StackNode(elem);
            newnode->next = this->top;
            this->top = newnode;
            this->currSize++;
        } catch(string message){
            cout << "Exception thrown: " + message << endl;
            exit(1);
        }
    }
    
    /**
     * @return the top element from the Stack and deletes it
     * @throws underflow exception
    */
    T pop(){
        try{
            if(this->currSize == 0){
                throw underflowException;
            }
            StackNode *tmp = this->top;
            T retValue = tmp->data;
            delete tmp;
            this->currSize--;
            if(this->currSize == 0){
                this->top = NULL;
            } else {
                this->top = this->top->next;
            }
            return retValue;
        } catch(string message){
            cout << "Exception thrown: " + message << endl;
            exit(1);
        }
    }

    /**
     * @return {@code true} if {@code currSize} is 0
    */
    bool isEmpty(){
        return this->currSize == 0;
    }
};

#endif // DEBUG