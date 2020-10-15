class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char> > row(9),col(9),box(9);
        for(int i =0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j] != '.') {
                    if(row[i].count(board[i][j])) return false;
                    if(col[j].count(board[i][j])) return false;
                    if(box[i/3+(j/3)*3].count(board[i][j])) return false;
                    row[i].insert(board[i][j]);
                    col[j].insert(board[i][j]);
                    box[i/3+(j/3)*3].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};
