class Solution
{
private:
    vector<int> dp;

public:
    int helper(vector<int> &nums, int target)
    {
        if (dp[target] != -1)
            return dp[target];
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (target >= nums[i])
            {
                res += helper(nums, target - nums[i]);
            }
        }
        dp[target] = res;
        return res;
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        dp.resize(target + 1, -1);
        dp[0] = 1;

        return helper(nums, target);
    }
};