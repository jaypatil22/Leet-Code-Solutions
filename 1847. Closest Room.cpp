class Solution
{
public:
    vector<int> closestRoom(vector<vector<int>> &rooms, vector<vector<int>> &queries)
    {
        const int q = queries.size();
        vector<int> res(q, -1);
        vector<int> inx(q, 0);
        iota(inx.begin(), inx.end(), 0);
        sort(inx.begin(), inx.end(), [&](const int &l, const int &r) { return queries[l][1] > queries[r][1]; });
        sort(rooms.begin(), rooms.end(), [](const auto &l, const auto &r) { return l[1] < r[1]; });
        set<int> room_id = {};
        for (const int a : inx)
        {
            while (!rooms.empty() && rooms.back()[1] >= queries[a][1])
            {
                room_id.insert(rooms.back()[0]);
                rooms.pop_back();
            }
            if (room_id.empty())
                continue;

            auto it = room_id.lower_bound(queries[a][0]);
            if (it == room_id.end())
                it = prev(room_id.end());
            int dist = abs(queries[a][0] - *it);
            int id = *it;
            it = prev(it);
            if (it != room_id.end() && (abs(queries[a][0] - *it) <= dist))
            {
                id = *it;
            }
            res[a] = id;
        }
        return res;
    }
};