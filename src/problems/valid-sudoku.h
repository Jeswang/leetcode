//
//  valid-sudoku.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

A partially filled sudoku which is valid.
Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

#define foreach(container,it) for(auto it = (container).begin();it!=(container).end();++it)
#define FD(X, Y) (X.find(Y)!=X.end())
#define SIZE(A) ((int)A.size())
#define PB(X) push_back(X)

class Solution {
public:
    vector<string> board_;
    int n;
    char checkNum;
    bool isValidSudoku(vector<string> &board) {
        n = SIZE(board);
        board_ = board;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (board_[i][j] == '.') {
                    continue;
                }
                else {
                    checkNum = board[i][j];
                }
                if(checkLine(i, j)==false || checkRow(i, j)==false || checkRect(i, j)==false){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool checkLine(int x, int y) {
        int count = 0;
        for (int i=0; i<n; i++) {
            if (board_[x][i] == checkNum) {
                count++;
            }
            if (count == 2) {
                return false;
            }
        }
        return true;
    }
    
    bool checkRow(int x, int y) {
        int count = 0;
        for (int i=0; i<n; i++) {
            if (board_[i][y] == checkNum) {
                count++;
            }
            if (count == 2) {
                return false;
            }
        }
        return true;
    }
    
    
    bool checkRect(int x, int y) {
        int beginY = (x/3)*3;
        int beginX = (y/3)*3;
        
        int count = 0;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (board_[beginY + i][beginX + j] == checkNum) {
                    count++;
                }
                if (count == 2) {
                    return false;
                }
            }
        }
        return true;
    }
        
    void run() {
        vector<string> test = {"....5..1.",".4.3.....",".....3..1","8......2.","..2.7....",".15......",".....2...",".2.9.....","..4......"};
        cout<<isValidSudoku(test);
    }
};