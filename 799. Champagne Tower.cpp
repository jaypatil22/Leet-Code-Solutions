class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[102][102] ={0.0};
        dp[0][0] = (double) poured;
        for(int i=0;i<=query_row;i++) {
            for(int j=0;j<=i;j++) {
                if(dp[i][j] > 1) {
                    double ex = (dp[i][j]-1)/2;
                    dp[i+1][j] += ex;
                    dp[i+1][j+1] += ex;
                }
            }
        }
        return min(1.0,dp[query_row][query_glass]);
    }
};