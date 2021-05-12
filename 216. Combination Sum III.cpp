class Solution
{
public:
    void backtrack(vector<vector<int>> &res, vector<int> &current, int k, int n, int start)
    {
        if (current.size() > k)
            return;
        if (n < 0)
            return;
        if (current.size() == k && n == 0)
        {
            res.emplace_back(current);
            return;
        }
        for (int i = start; i <= 9; i++)
        {
            current.emplace_back(i);
            backtrack(res, current, k, n - i, i + 1);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> current;
        if (k > n)
            return res;
        backtrack(res, current, k, n, 1);
        return res;
    }
};