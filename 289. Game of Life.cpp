class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                int cnt = 0;
                if(i-1 >=0) {
                    if(board[i-1][j]==1 || board[i-1][j]==2) cnt++;
                }
                if(j-1 >=0) {
                    if(board[i][j-1]==1 || board[i][j-1]==2) cnt++;
                }
                if(i+1 < board.size()) {
                    if(board[i+1][j]==1 || board[i+1][j]==2) cnt++;
                }
                if(j+1 <board[0].size()) {
                    if(board[i][j+1]==1 || board[i][j+1]==2) cnt++;
                }
                if(i-1 >=0 && j-1>=0) {
                    if(board[i-1][j-1]==1 || board[i-1][j-1]==2) cnt++;
                }
                if(i+1 <board.size() && j+1<board[0].size()) {
                    if(board[i+1][j+1]==1 || board[i+1][j+1]==2) cnt++;
                }
                if(i-1>=0 && j+1<board[0].size()) {
                    if(board[i-1][j+1]==1 || board[i-1][j+1]==2) cnt++;
                }
                if(i+1 <board.size() && j-1>=0) {
                    if(board[i+1][j-1]==1 || board[i+1][j-1]==2) cnt++;
                }
                if(board[i][j]==1) {
                    if(cnt<2) board[i][j] = 2;
                    else if(cnt > 3) board[i][j] = 2;
                } else {
                    if(cnt == 3) board[i][j] = 3;
                }
            }
        }
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(board[i][j]==2) board[i][j] = 0;
                else if(board[i][j]==3) board[i][j] = 1;
            }
        }
    }
};