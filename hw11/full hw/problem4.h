/**
 * Solution for problem 4
 * @author Dushan Terzikj
 * @since 21.05.2018
*/
#include <bits/stdc++.h>
using namespace std;

#ifndef _PUZZLE_BOARD_H
#define _PUZZLE_BOARD_H

/**
 * This class represents a puzzle board.
*/
class PuzzleBoard{
    
    vector< set<int> > edges; // edges in the graph
    vector< vector<int> > fields; // the fields on the puzzle board
    int numOfNodes; // the number of nodes (boardSize^2)
    int boardSize; // the board size
    int currX, currY; // current X and Y coordinates on the puzzle

    /**
     * @param x coordinate on the i axis
     * @param y coordinate on the j axis
     * @return int - the node on position (i, j) --> i*boardSize+j
    */
    int getNode(const int& x, const int& y);
    /**
     * @return true if (x, y) is out of the boundaries of the board
    */
    bool outOfBounds(const int& x, const int& y);

public: 

    /**
     * Default constructor. Sets up the graph as explained in problem4.pdf
     * @param boardSize
     * @param fields[][] - the puzzle board fields
    */
    PuzzleBoard(int boardSize, int **fields = NULL);

    /**
     * Makes a move up, down, left or right. 
     * @param direction - 0 is up, 1 is right, 2 is down, 3 is left
     * @return true if a move is valid (inside the boundaries of the board), false otherwise 
    */
    bool makeMove(int direction);

    /**
     * @return true if game is finished, false otherwise
    */
    bool getResult();

    /**
     * Prints the fields board.
    */
    friend ostream& operator<<(ostream &os, const PuzzleBoard& m);

    /**
     * Solves the puzzle using BFS algorithm.
     * @return int - minimum number of steps used to solve the puzzle.
    */
    int solve();
};

#endif