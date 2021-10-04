class Solution {
public:
    string check(vector<string> &grid) {
        string res = "";
        if(grid[0][0] != ' ' && grid[0][0]==grid[0][1] && grid[0][0]==grid[0][2]) {
            return res + grid[0][0];
        }
        if(grid[0][0] != ' ' && grid[0][0]== grid[1][1] && grid[0][0]==grid[2][2]) {
            return res + grid[0][0];
        }
        if(grid[0][0] != ' ' && grid[0][0]== grid[1][0] && grid[0][0]==grid[2][0]) {
            return res + grid[0][0];
        }
        if(grid[1][0] != ' ' && grid[1][0]== grid[1][1] && grid[1][0]==grid[1][2]) {
            return res + grid[1][0];
        }
        if(grid[2][0] != ' ' && grid[2][0]== grid[2][1] && grid[2][0]==grid[2][2]) {
            return res + grid[2][0];
        }
        if(grid[0][1] != ' ' && grid[0][1]== grid[1][1] && grid[0][1]==grid[2][1]) {
            return res + grid[0][1];
        }
        if(grid[0][2] != ' ' && grid[0][2]== grid[1][2] && grid[0][2]==grid[2][2]) {
            return res + grid[0][2];
        }
        if(grid[0][2] != ' ' && grid[0][2]== grid[1][1] && grid[0][2]==grid[2][0]) {
            return res + grid[0][2];
        }
        return res;
    }
    string tictactoe(vector<vector<int>>& moves) {
        vector<string> grid(3,string(3,' '));
        for(int i=0;i<moves.size();i++) {
            char xo = i%2 ? 'B' : 'A';
            grid[moves[i][0]][moves[i][1]] = xo;
            string win = check(grid);
            if(win != "") return win;
        }
        if(moves.size()==9) return "Draw";
        else return "Pending";
    }
};