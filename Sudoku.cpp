class Solution {
public:
    bool solve(vector<vector<char>>& board){
        for(int row = 0 ; row<9 ; row++){
            for(int col = 0 ; col <9 ; col++){
                if(board[row][col]=='.'){
                    for(char num = '1'; num<='9' ; num++){
                        if(isSafe(board,row,col,num)){
                            board[row][col] = num;
                            if(solve(board)){
                                return true;
                            }
                            board[row][col]='.';
                        }
                        
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isSafe(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num || board[i][col] == num) return false;
        }
        int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == num) {
                    return false;
                }
            }
        }
        return true;
        }
        void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};