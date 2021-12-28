class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix[0].size(), m = matrix.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int res = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j]=='1') {
                    dp[i+1][j+1] = min(dp[i][j],min(dp[i+1][j],dp[i][j+1])) + 1;
                    res = max(res,dp[i+1][j+1]);
                }
            }
        }
        return res*res;
    }
};
