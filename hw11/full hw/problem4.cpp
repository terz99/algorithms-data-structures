/**
 * Solution for problem 4
 * @author Dushan Terzikj
 * @since 21.05.2018
*/
#include <bits/stdc++.h>
#include "problem4.h"
using namespace std;


   
int PuzzleBoard::getNode(const int& x, const int& y){
    return (x*boardSize + y);
}


bool PuzzleBoard::outOfBounds(const int& x, const int& y){
    return x < 0 || x >= boardSize || y < 0 || y >= boardSize;
}

PuzzleBoard::PuzzleBoard(int boardSize, int **fields){
    if(fields == NULL){
        
        /* If fields is NULL, generate a random board */
        
        srand(time(NULL));
        fields = new int*[boardSize];
        if(fields == NULL) exit(1); // Bad allocation
        for(int i = 0; i < boardSize; i++){
            fields[i] = new int[boardSize];
            if(fields[i] == NULL) exit(1); // Bad allocation
            for(int j = 0; j < boardSize; j++){
                fields[i][j] = rand()%boardSize + 1;
            }
        }
    }

    /* Initialization and setting the graph */
    this->boardSize = boardSize;
    numOfNodes = boardSize*boardSize;
    edges.resize(numOfNodes, set<int>());
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++){
            int currNode = getNode(i, j);
            int nextNode;
            if(!outOfBounds(i + fields[i][j], j)){
                nextNode = getNode(i + fields[i][j], j);
                edges[currNode].insert(nextNode);
            }
            if(!outOfBounds(i - fields[i][j], j)){
                nextNode = getNode(i - fields[i][j], j);
                edges[currNode].insert(nextNode);
            }
            if(!outOfBounds(i, j + fields[i][j])){
                nextNode = getNode(i, j + fields[i][j]);
                edges[currNode].insert(nextNode);
            }
            if(!outOfBounds(i, j - fields[i][j])){
                nextNode = getNode(i, j - fields[i][j]);
                edges[currNode].insert(nextNode);
            }
        }
    }

    /* Copying the fields */
    this->fields.resize(boardSize, vector<int>(boardSize));
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++){
            this->fields[i][j] = fields[i][j];
        }
    }
    /* Set initial position to (0, 0) */
    currX = currY = 0;
}

bool PuzzleBoard::makeMove(int direction){
    int nx, ny, curr, next;
    set<int>::iterator it;
    switch(direction){
        case 0:

            nx = currX - fields[currX][currY];
            ny = currY;
            if(outOfBounds(nx, ny)){
                return false;
            }
            curr = getNode(currX, currY);
            next = getNode(nx, ny);
            it = edges[curr].find(next);
            if(it == edges[curr].end()){
                return false;
            }
            currX = nx;
            currY = ny;

        break;
        case 1:

            nx = currX;
            ny = currY + fields[currX][currY];
            if(outOfBounds(nx, ny)){
                return false;
            }
            curr = getNode(currX, currY);
            next = getNode(nx, ny);
            it = edges[curr].find(next);
            if(it == edges[curr].end()){
                return false;
            }
            currX = nx;
            currY = ny;

        break; 
        case 2:

            nx = currX + fields[currX][currY];
            ny = currY;
            if(outOfBounds(nx, ny)){
                return false;
            }
            curr = getNode(currX, currY);
            next = getNode(nx, ny);
            it = edges[curr].find(next);
            if(it == edges[curr].end()){
                return false;
            }
            currX = nx;
            currY = ny;

        break;
        case 3:

            nx = currX;
            ny = currY - fields[currX][currY];
            if(outOfBounds(nx, ny)){
                return false;
            }
            curr = getNode(currX, currY);
            next = getNode(nx, ny);
            it = edges[curr].find(next);
            if(it == edges[curr].end()){
                return false;
            }
            currX = nx;
            currY = ny;

        break;
    }
    return true;
}

bool PuzzleBoard::getResult(){
    return (currX == boardSize-1 && currY == boardSize-1);
}

int PuzzleBoard::solve(){

    int d[numOfNodes];
    memset(d, -1, sizeof(d));
    queue<int> q;
    d[0] = 0;
    q.push(0);
    while(!q.empty()){
        
        int curr = q.front();
        q.pop();

        for(auto next : edges[curr]){
            if(d[next] == -1){
                d[next] = d[curr] + 1;
                q.push(next);
            }
        }
    }

    if(d[numOfNodes-1] == -1){
        cout << "No solution\n";
    }
    return d[numOfNodes];
}

ostream& operator<<(ostream& os, const PuzzleBoard& m){
    for(int i = 0; i < m.boardSize; i++){
        for(int j = 0; j < m.boardSize; j++){
            os << m.fields[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

/**
 * Test driver function. If you want to use it, implement it, otherwise delete it or uncomment it.
 * Do not grade it!
*/
int main(){

    cout << "Main function not implemented. If you want to use it, implement your test code. Otherwise delete it or comment it. Do not grade it!\n";

    return 0;
}