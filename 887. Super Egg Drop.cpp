class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<int> dp(n+1,0);
        for(int i=0;i<=n;i++) {
            dp[i] = i;
        }
        
        for(int i = 2;i<=k;i++) {
            vector<int> dp2(n+1,0);
            int x = 1;
            for(int j =1 ;j<=n;j++) {
                
                while(x<j && (max(dp2[j-x],dp[x-1]) > max(dp[x],dp2[j-x-1]))) x++;
                
                dp2[j] = 1 + max(dp2[j-x],dp[x-1]);
            }
            dp = dp2;
        }
        return dp[n];
    }
};