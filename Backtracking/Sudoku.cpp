/*
Sudoku Solver
Send Feedback
Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.
Input Format :
9 Lines where ith line contains ith row elements separated by space
Output Format :
 true or false
Sample Input :
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output :
true
*/
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<string>
#include<cstring>
#include<unordered_set>
#include<unordered_set>
#include<algorithm>
#include<set>
#include<cmath>
//#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isColumnPossible(int board[9][9], int num, int col) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
    return true;
}
bool isRowPossible(int board[9][9], int num, int row) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }
    return true;
}

bool isGridPossible(int board[9][9], int num, int row, int col) {
    int rowStart = row - row % 3;
    int colStart = col - col % 3;
    for (int i = rowStart; i < rowStart + 3; i++) {
        for (int j = colStart; j < colStart + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool isPossibleNum(int board[9][9], int num, int row, int col) {
    if (isColumnPossible(board, num, col)) {
        if (isRowPossible(board, num, row)) {
            if (isGridPossible(board, num, row, col)) {
                return true;
            }
        }
    }
   
    return false;
}

bool solver(int board[9][9]) {
    int row;
    int col;
    bool emptyCheck = false;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                emptyCheck = true;
                break;
            }
        }
        if (emptyCheck)
            break;
    }


    if (!emptyCheck)
        return true;


    for (int num = 1; num <= 9; num++) {
        if (isPossibleNum(board, num, row, col)) {
            board[row][col] = num;
            if (solver(board)) {
                return true;
            }
            board[row][col] = 0;

        }

    }

    return false;
}


bool sudokuSolver(int board[9][9]) {

    return solver(board);
}