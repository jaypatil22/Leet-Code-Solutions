class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()<=1) return 0;
        vector<vector<int>> dp(k+1,vector<int>(prices.size(),0));
        for(int i=1;i<=k;i++) {
            int m = dp[i-1][0] - prices[0];
            for(int j=1;j<prices.size();j++) {
                int res = dp[i][j-1];
                m = max(dp[i-1][j-1] - prices[j-1],m);
                res = max(res,m + prices[j]);
                dp[i][j] = res;
            }
        }
        return dp[k][prices.size()-1];
    }
};