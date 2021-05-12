class Solution
{
    void dfs(int cur, vector<int> &res, int &n)
    {
        if (cur > n)
            return;
        else
        {
            res.push_back(cur);
            for (int i = 0; i < 10; i++)
            {
                if (cur * 10 + i > n)
                    return;
                dfs(cur * 10 + i, res, n);
            }
        }
    }

public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> res;
        for (int i = 1; i < 10; i++)
        {
            dfs(i, res, n);
        }
        return res;
    }
};