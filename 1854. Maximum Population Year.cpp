class Solution
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        sort(logs.begin(), logs.end());
        vector<int> dp(101, 0);
        for (int i = 0; i < logs.size(); i++)
        {
            for (int j = logs[i][0] - 1950; j < logs[i][1] - 1950; j++)
            {
                dp[j] += 1;
            }
        }
        int res = 0, ma = INT_MIN;
        for (int i = 0; i <= 100; i++)
        {
            if (dp[i] > ma)
            {
                ma = dp[i];
                res = i;
            }
        }
        return res + 1950;
    }
};