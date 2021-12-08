class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        
        vector<vector<int>> dp(n,vector<int> (m,0));
        for(int i=0;i<n;i++) {
            int temp = 0;
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1) temp++;
                else temp = 0;
                
                dp[i][j] = temp;
            }
            temp = 0;
            for(int j=m-1;j>=0;j--) {
                if(grid[i][j]==1) temp++;
                else temp = 0;
                
                dp[i][j] = min(dp[i][j],temp);
            }
        }
        int res = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(dp[i][j]==0) continue;
                
                int k = 0;
                while(i+k<n && dp[i+k][j] >= k+1) k++;
                res += (k-1);
                k = 0;
                while(i-k>=0 && dp[i-k][j] >= k+1) k++;
                res += (k-1);
            }
        }
        return res;
    }
};