class Solution
{
public:
    int change(int t, vector<int> &cs)
    {
        vector<vector<int>> dp(cs.size() + 1, vector<int>(t + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= cs.size(); i++)
        {
            dp[i][0] = 1;
            for (auto j = 1; j <= t; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - cs[i - 1] >= 0)
                {
                    dp[i][j] += dp[i][j - cs[i - 1]];
                }
            }
        }
        return dp[cs.size()][t];
    }
};