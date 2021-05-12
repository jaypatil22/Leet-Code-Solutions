class Solution
{
public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        vector<int> dp(stoneValue.size(), -1e9);
        for (int i = stoneValue.size() - 1; i >= 0; i--)
        {
            for (int j = 0, take = 0; j < 3 && i + j < stoneValue.size(); j++)
            {
                take += stoneValue[i + j];
                dp[i] = max(dp[i], take - (i + j + 1 < stoneValue.size() ? dp[i + j + 1] : 0));
            }
        }
        if (dp[0] > 0)
            return "Alice";
        else if (dp[0] < 0)
            return "Bob";
        return "Tie";
    }
};