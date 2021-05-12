class Solution {
    bool solved=false;
public:
    bool issafe(vector<vector<char>> &board,int row,int col,char c) {
        for(int i=0;i<9;i++) {
            if(board[row][i]==c)
                return false;
            if(board[i][col]==c)
                return false;
        }
        int r=row/3,co=col/3;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(board[r*3+i][co*3+j]==c) {
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int row=-1,col=-1;
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j]=='.') {
                  row=i;col=j;  
                }
            }
        }
        if(row==-1) {
            solved=true;
            return;
        }
        for(int i=1;i<=9;i++) {
            if(issafe(board,row,col,i+'0')) {
                board[row][col]=i+'0';
                solveSudoku(board);
                if(solved) return;
                board[row][col]='.';
            }
        }
    }
};