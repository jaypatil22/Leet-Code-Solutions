class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int l=n-1;l>=0;l--) {
            for(int r=l;r<n;r++) {
                for(int i=l;i<=r;i++) {
                    dp[l][r] = max(dp[l][r],(nums[i]*(l-1>=0?nums[l-1]:1)*(r+1<n?nums[r+1]:1)+(i+1<=r?dp[i+1][r]:0)+(i-1>=l?dp[l][i-1]:0)));
                }
            }
        }
        return dp[0][n-1];
    }
};