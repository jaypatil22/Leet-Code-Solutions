class Solution {
public:
    const int mod = 1e9+7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<long long>>> dp(m,vector<vector<long long>> (n,vector<long long>(maxMove+1,-1)));
        return recurse(dp,m,n,startRow,startColumn,maxMove);
    }
    
    long long recurse(vector<vector<vector<long long>>> &dp,int m,int n,int i,int j,int moves) {
        if(i==m || j==n || i<0 || j<0) return 1;
        if(moves==0) return 0;
        if(dp[i][j][moves]>=0) return dp[i][j][moves];
        dp[i][j][moves] = ((recurse(dp,m,n,i+1,j,moves-1)+recurse(dp,m,n,i-1,j,moves-1))%mod + (recurse(dp,m,n,i,j+1,moves-1)+recurse(dp,m,n,i,j-1,moves-1)%mod));
        return dp[i][j][moves]%mod;
    }
};