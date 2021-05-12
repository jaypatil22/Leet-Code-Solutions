class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(colors.size()), cnt(colors.size(), vector<int>(26, 0));
        vector<int> q, indegree(colors.size());
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        for (int i = 0; i < colors.size(); i++)
        {
            if (indegree[i] == 0)
                q.push_back(i);
        }
        int res = 0, processed = 0;
        while (!q.empty())
        {
            vector<int> q1;
            for (auto i : q)
            {
                processed++;
                res = max(res, ++cnt[i][colors[i] - 'a']);
                for (auto j : adj[i])
                {
                    for (int k = 0; k < 26; k++)
                    {
                        cnt[j][k] = max(cnt[j][k], cnt[i][k]);
                    }
                    if (--indegree[j] == 0)
                        q1.push_back(j);
                }
            }
            swap(q, q1);
        }
        return processed != colors.size() ? -1 : res;
    }
};