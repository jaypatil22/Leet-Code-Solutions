class Solution {
public:
    int helper(vector<vector<int>> &dungeon, vector<vector<int>> &dp,int i=0,int j=0) {
        int n = dungeon.size(), m = dungeon[0].size();
        if(i==n || j==m) return 1e9+5;
        
        if(i==n-1 and j==m-1) {
            return dungeon[i][j] <= 0 ? 1 + (-dungeon[i][j]) : 1;
        }
        if(dp[i][j] != 1e9+5) return dp[i][j];
        int right = helper(dungeon,dp,i,j+1);
        int down = helper(dungeon,dp,i+1,j);
        
        int res = min(right,down) - dungeon[i][j];
        
        dp[i][j] = (res <=0 ? 1 : res);
        return dp[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(),m = dungeon[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,1e9+5));
        return helper(dungeon,dp);
    }
};