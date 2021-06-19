class Solution {
public:
    vector<vector<int>> dp;
    int recurse(vector<int> &stones,int l,int r,int sum) {
        if(l==r) return 0;
        
        return dp[l][r] ? dp[l][r] : dp[l][r] = max(sum-stones[l] - recurse(stones,l+1,r,sum-stones[l]),sum-stones[r] - recurse(stones,l,r-1,sum-stones[r]));
    }
    int stoneGameVII(vector<int>& stones) {
        int sum = 0;
        dp.resize(1000,vector<int> (1000,0));
        for(int i=0;i<stones.size();i++) {
            sum += stones[i];
        }
        int l = 0,r= stones.size()-1;
        return recurse(stones,l,r,sum);
    }
};