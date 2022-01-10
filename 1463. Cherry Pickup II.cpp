class Solution {
public:
    vector<vector<vector<int>>> v;
    int helper(vector<vector<int>> &grid,int row,int col1,int col2) {
        if(col1<0 || col2<0 || col1>=grid[0].size() || col2>=grid[0].size() || row >= grid.size()) return -1;
        if(v[row][col1][col2]!=-1) return v[row][col1][col2];
        int res = 0;
        for(int i=-1;i<2;i++) {
            for(int j=-1;j<2;j++) {
                res = max(res,helper(grid,row+1,col1+i,col2+j));
            }
        }
        if(col1==col2) res += grid[row][col1];
        else res += (grid[row][col1]+grid[row][col2]);
        v[row][col1][col2] = res;
        return res;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        v.resize(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        return helper(grid,0,0,grid[0].size()-1);
    }
};