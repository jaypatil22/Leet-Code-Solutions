class Solution {
public:
    int dfs(vector<vector<int>> &grid,int x, int y, int empty) {
        if(x<0 || y < 0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]==-1) return 0;
        if(grid[x][y]==2) return empty==-1;
        grid[x][y] = -1;
        int res = dfs(grid,x+1,y,empty-1)+dfs(grid,x-1,y,empty-1) + dfs(grid,x,y+1,empty-1) + dfs(grid,x,y-1,empty-1);
        grid[x][y] = 0;
        return res;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int empty = 0, sx,sy;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==1) sx = i, sy = j;
                if(grid[i][j]==0) empty++;
            }
        }
        return dfs(grid,sx,sy,empty);
    }
};