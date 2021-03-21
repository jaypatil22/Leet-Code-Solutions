class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int cur = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                cur += nums[i];
            }
            else
            {
                if (cur > res)
                {
                    res = cur;
                }
                cur = nums[i];
            }
        }
        if (cur > res)
            res = cur;
        return res;
    }
};