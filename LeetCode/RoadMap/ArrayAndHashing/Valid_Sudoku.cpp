//
// Created by Elizaveta Gribacheva on 14.10.2025.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_set>
using namespace std;
typedef long long ll;

bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        unordered_set<char> col;
        unordered_set<char> row;

        for (int j = 0; j < 9; j++) {
            if (board[j][i] != '.') {
                if (col.count(board[j][i])){
                    return false;
                }else{ col.insert(board[j][i]);}
            }

            if(board[i][j] != '.'){
                if (row.count(board[i][j])) {
                    return false;
                }else{
                    row.insert(board[i][j]);
                }
            }
        }
    }

    for (int k = 0; k < 9; k++) {
        unordered_set<char> collumn;
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < 3; i++) {
                int row = (k/3) *3 +j;
                int col = (k%3)*3 + i;
                if (board[row][col] == '.') continue;
                if (collumn.count(board[row][col])) {
                    return false;
                }
                collumn.insert(board[row][col]);
            }
        }
    }

    return true;
}

int main() {
    vector<vector<char>> board = {
        {'1','2','.','.','3','.','.','.','.'},
        {'4','.','.','5','.','.','.','.','.'},
        {'.','9','1','.','.','.','.','.','3'},
        {'5','.','.','.','6','.','.','.','4'},
        {'.','.','.','8','.','3','.','.','5'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','.','.','.','.','.','2','.','.'},
        {'.','.','.','4','1','9','.','.','8'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << isValidSudoku(board) << endl;

}