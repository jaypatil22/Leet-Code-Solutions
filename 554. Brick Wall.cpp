class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        unordered_map<int, int> m;
        int width, res = wall.size(), b = wall.size();
        for (auto a : wall)
        {
            for (int i = 0, width = 0; i < a.size() - 1; i++)
            {
                res = min(res, b - (++m[width += a[i]]));
            }
        }
        return res;
    }
};