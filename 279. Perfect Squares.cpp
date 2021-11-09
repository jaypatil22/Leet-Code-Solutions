class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 0;
        for(int i=1;i<=n;i++) {
            int cur = i;
            for(int j=1;j*j<=i;j++) {
                if(cur > dp[i-j*j]+1) cur = dp[i-j*j]+1;
            }
            dp[i] = cur;
        }
        return dp[n];
    }
};