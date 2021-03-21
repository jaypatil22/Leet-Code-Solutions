class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int pre = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (pre < i)
                return false;
            pre = max(nums[i] + i, pre);
        }
        return true;
    }
};