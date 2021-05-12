class Solution
{
public:
    void rec(vector<vector<int>> &res, vector<int> &current, vector<int> &nums, int i)
    {
        if (i >= nums.size())
            return;
        current.emplace_back(nums[i]);
        res.emplace_back(current);
        for (int j = i + 1; j < nums.size(); j++)
            rec(res, current, nums, j);
        current.pop_back();
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> current;
        res.emplace_back(current);
        for (int i = 0; i < nums.size(); i++)
        {
            rec(res, current, nums, i);
        }
        return res;
    }
};