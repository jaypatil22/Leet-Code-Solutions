class Solution
{
public:
    bool winnerSquareGame(int n)
    {
        vector<bool> dp(n + 1, false);
        dp[0] = false;
        dp[1] = true;
        dp[2] = false;
        for (int i = 0; i <= n; i++)
        {
            if (dp[i] == 0)
            {
                for (int j = 1; i + j * j <= n; j++)
                {
                    dp[i + j * j] = true;
                }
            }
        }
        return dp[n];
    }
};