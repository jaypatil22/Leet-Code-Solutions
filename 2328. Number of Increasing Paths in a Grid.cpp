class Solution {
public:
    int count(vector<vector<int>>&grid, vector<vector<int>> &dp,int i, int j) {
        if(dp[i][j]!=-1) return dp[i][j];
        int res = 1;
        int mod = 1e9+7;
        if(i-1>=0 && grid[i][j]<grid[i-1][j]) {
            res = (res + count(grid,dp,i-1,j))%mod;
        }
        if(i+1<grid.size() && grid[i][j]<grid[i+1][j]) {
            res = (res + count(grid,dp,i+1,j))%mod;
        }
        if(j-1>=0 && grid[i][j]<grid[i][j-1]) {
            res = (res + count(grid,dp,i,j-1))%mod;
        }
        if(j+1<grid[0].size() && grid[i][j]<grid[i][j+1]) {
            res = (res + count(grid,dp,i,j+1))%mod;
        }
        dp[i][j] = res;
        return res;
    }
    int countPaths(vector<vector<int>>& grid) {
        int mod = 1e9+7;
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        int res = 0;
        for(int i = 0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                res = (res + count(grid,dp,i,j))%mod;
            }
        }
        // int res = 0;
        // for(int i=0;i<grid.size();i++) {
        //     for(int j=0;j<grid[0].size();j++) {

        //     }
        // }
        return res;
    }
};