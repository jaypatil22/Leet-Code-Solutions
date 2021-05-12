class Solution
{
public:
    void backtrack(vector<vector<int>> &res, vector<int> &candidates, int target, vector<int> current, int index)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            res.emplace_back(current);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            current.emplace_back(candidates[i]);
            backtrack(res, candidates, target - candidates[i], current, i + 1);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(res, candidates, target, current, 0);
        return res;
    }
};