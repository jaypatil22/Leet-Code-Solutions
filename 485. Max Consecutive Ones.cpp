class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int res = 0, current = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i])
            {
                current++;
            }
            else
            {
                if (current > res)
                {
                    res = current;
                }
                current = 0;
            }
        }
        if (current > res)
            res = current;
        return res;
    }
};