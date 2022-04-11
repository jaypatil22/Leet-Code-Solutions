class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> res(grid.size(),vector<int> (grid[0].size(),0));
        int m = grid.size(),n = grid[0].size();
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                int col = (k+j)%n;
                int row = (i+(k+j)/n)%m;
                res[row][col] = grid[i][j];
            }
        }
        return res;
    }
};