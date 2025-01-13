//N- Queen Problem 
// https://leetcode.com/problems/n-queens/


class Solution {
public:
       bool isSafe(int x ,int y ,vector<string> &board,int n){
        for(int i =0 ;i<x;i++){
            if(board[i][y]=='Q'){  //same column
                return false;
            }
        }
         for(int i =x-1, j = y-1 ;i>=0 && j >=0;i--,j--){
            if(board[i][j]=='Q'){  // left diagonal
                return false;
            }
        }
         for(int i =x-1, j = y+1 ;i>=0 && j<n ;i--,j++){
            if(board[i][j]=='Q'){  // right diagonal
                return false;
            }
        }
            return true;
       }

    void solve(int x, vector<string> &board, vector<vector<string>> &solutions, int n) {
        if (x == n) {
            solutions.push_back(board);
            return;
        }
        for (int y = 0; y < n; y++) {
            if (isSafe(x, y, board, n)) {
                board[x][y] = 'Q';
                solve(x + 1, board, solutions, n);
                board[x][y] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        solve(0, board, solutions, n);
        return solutions;
    }
};