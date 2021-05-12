class Solution
{
    void dfs(vector<vector<int>> &res, vector<int> &cur, int c, vector<vector<int>> &graph)
    {
        cur.push_back(c);
        if (c == graph.size() - 1)
        {
            res.push_back(cur);
            cur.pop_back();
            return;
        }
        for (int i = 0; i < graph[c].size(); i++)
        {
            dfs(res, cur, graph[c][i], graph);
        }
        cur.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, cur, 0, graph);
        return res;
    }
};