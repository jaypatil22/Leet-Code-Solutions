class Solution
{
public:
    int pass(vector<vector<int>> &r)
    {
        int res = 0;
        for (int i = 0; i < r.size() - 1; i++)
        {
            int h1 = r[i][1], h2 = r[i + 1][1];
            int h = h1 + abs(r[i][0] - r[i + 1][0]);
            if (h > h2)
                h = h2 + (h - h2) / 2;
            res = max(h, res);
            r[i + 1][1] = min(h, h2);
        }
        return res;
    }
    int maxBuilding(int n, vector<vector<int>> &restrictions)
    {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        sort(restrictions.begin(), restrictions.end());
        pass(restrictions);
        reverse(restrictions.begin(), restrictions.end());
        return pass(restrictions);
    }
};