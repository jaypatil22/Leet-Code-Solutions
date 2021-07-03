class Solution {
public:
    void isSub(vector<vector<int>> &grid1,vector<vector<int>> &grid2,int row,int col,vector<vector<bool>>&visited,bool &flag) {
        if(row<0 || col<0 || row>=grid1.size() || col>=grid1[0].size() || visited[row][col]) return;
        if(grid2[row][col]==0) return;
        visited[row][col] = true;
        if(grid1[row][col]==0) flag = false;
        isSub(grid1,grid2,row+1,col,visited,flag);
        isSub(grid1,grid2,row,col+1,visited,flag);
        isSub(grid1,grid2,row-1,col,visited,flag);
        isSub(grid1,grid2,row,col-1,visited,flag);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<bool>> visited(grid2.size(),vector<bool> (grid1[0].size(),false));
        int res = 0;
        for(int i=0;i<grid2.size();i++) {
            for(int j=0;j<grid2[0].size();j++) {
                if(grid2[i][j]==1 && !visited[i][j]) {
                    bool flag = true;
                    isSub(grid1,grid2,i,j,visited,flag);
                    if(flag) res++;
                }
            }
        }
        return res;
    }
};