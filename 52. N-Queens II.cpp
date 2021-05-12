class Solution {
public:
    bool issafe(vector<string> &board,int row,int col) {
        // for(int i=0;i<board[0].size();i++) {
        //     if(board[row][i]=='1')
        //         return false;
        // }
        for(int i=0;i!=row;i++) {
            if(board[i][col]=='Q')
                return false;
        }
        for(int i=1;row-i>=0&&col-i>=0;i++) {
            if(board[row-i][col-i]=='Q')
                return false;
        }
        for(int i=1;row-i>=0&&col+i<board.size();i++) {
            if(board[row-i][col+i]=='Q')
                return false;
        }
        return true;
    }
    void backtrack(int &res,vector<string> &board,int row) {
        if(row==board.size()) {
            res++;
            return;
        }
        for(int i=0;i<board[0].size();i++) {
            if(issafe(board,row,i)) {
                board[row][i]='Q';
                backtrack(res,board,row+1);
                board[row][i]='.';
            }
        }
        return;
    }
    int totalNQueens(int n) {
        int res=0;
        vector<string> board(n,string(n,'.'));
        backtrack(res,board,0);
        return res;
    }
};