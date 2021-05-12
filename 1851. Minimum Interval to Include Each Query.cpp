class Solution
{
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
    {
        sort(intervals.begin(), intervals.end());
        vector<int> res(queries.size(), -1);
        vector<int> order(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            order[i] = i;
        }
        sort(order.begin(), order.end(), [&](const int &l, const int &r) { return queries[l] < queries[r]; });

        set<pair<int, int>> s = {};
        int ptr = -1;
        for (int i : order)
        {
            int qi = queries[i];
            while (ptr + 1 < intervals.size() && intervals[ptr + 1][0] <= qi)
            {
                ptr++;
                s.insert({intervals[ptr][1] - intervals[ptr][0] + 1, intervals[ptr][1]});
            }
            while (!s.empty() && s.begin()->second < qi)
            {
                s.erase(s.begin());
            }
            if (s.empty())
                continue;

            res[i] = s.begin()->first;
        }
        return res;
    }
};