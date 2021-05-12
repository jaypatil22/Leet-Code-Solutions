class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        vector<int> res, idx(tasks.size());
        priority_queue<pair<int, int>> pq;
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) { return tasks[i][0] < tasks[j][0]; });
        for (long i = 0, time = 1; i < tasks.size() || !pq.empty();)
        {
            for (; i < tasks.size() && time >= tasks[idx[i]][0]; i++)
            {
                pq.push({-tasks[idx[i]][1], -idx[i]});
            }
            if (!pq.empty())
            {
                auto [proc, j] = pq.top();
                pq.pop();
                time -= proc;
                res.emplace_back(-j);
            }
            else
            {
                time = tasks[idx[i]][0];
            }
        }

        return res;
    }
};