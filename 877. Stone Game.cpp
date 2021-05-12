class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0, k = i - 1; k < n; j++, k++)
            {
                int turn = (j + k + n) % 2;
                if (turn)
                {
                    dp[j + 1][k + 1] = max(piles[j] + dp[j + 2][k + 1], piles[k] + dp[j + 1][k]);
                }
                else
                {
                    dp[j + 1][k + 1] = min(-piles[j] + dp[j + 2][k + 1], -piles[k] + dp[j + 1][k]);
                }
            }
        }
        return dp[1][n] > 0;
    }
};