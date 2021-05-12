class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        vector<int> sufsum(piles.begin(),piles.end());
        for(int i=piles.size()-2;i>=0;i--) sufsum[i]+=sufsum[i+1];
        vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),0));
        return dfs(sufsum,1,0,dp);
    }
    
    int dfs(vector<int> &sufsum,int m,int p,vector<vector<int>> &dp) {
        if(p+2*m>=sufsum.size()) {
            return sufsum[p];
        }
        if(dp[p][m]>0) return dp[p][m];
        int take=0,res=0;
        for(int i=1;i<=2*m;i++) {
            take = sufsum[p]-sufsum[p+i];
            res = max(res,take + sufsum[p+i] - dfs(sufsum,max(m,i),p+i,dp));
        }
        dp[p][m]= res;
        return res;
    }
};