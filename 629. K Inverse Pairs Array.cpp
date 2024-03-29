class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(1001,vector<int>(1001,0));
        const int mod = 1e9+7;
        for(int i=1;i<=n;i++) {
            for(int j=0;j<=k;j++) {
                if(j==0) {
                    dp[i][j] = 1;
                } else {
                    int val = (dp[i-1][j]+mod-(j-i>=0?dp[i-1][j-i]:0))%mod;
                    dp[i][j] = (val + dp[i][j-1])%mod;
                }
            }
        }
        return (dp[n][k]+mod-(k>0?dp[n][k-1]:0))%mod;
    }
};