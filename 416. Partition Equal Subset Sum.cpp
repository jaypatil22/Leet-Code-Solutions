class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();
        for (int a : nums)
        {
            sum += a;
        }
        if (sum & 1)
            return false;
        sum /= 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        dp[0][0] = true;
        for (int i = 0; i < n + 1; i++)
            dp[i][0] = true;
        for (int i = 0; i < sum + 1; i++)
            dp[0][i] = false;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1])
                {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][sum];
    }
};