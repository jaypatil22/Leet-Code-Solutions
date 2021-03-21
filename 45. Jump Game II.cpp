class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return 0;
        }
        vector<int> steps(nums.size(), 1000);
        steps[0] = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] + i >= nums.size() - 1)
            {
                return steps[i] + 1;
            }
            for (int j = i + 1; j <= i + nums[i]; j++)
            {
                steps[j] = min(steps[j], steps[i] + 1);
            }
        }
        return -1;
    }
};