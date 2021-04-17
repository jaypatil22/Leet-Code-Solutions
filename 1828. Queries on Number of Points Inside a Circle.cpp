class Solution
{
public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
    {
        vector<int> res;
        for (int i = 0; i < queries.size(); i++)
        {
            int xc = queries[i][0], yc = queries[i][1], r = queries[i][2], count = 0;
            for (int j = 0; j < points.size(); j++)
            {
                int x = points[j][0], y = points[j][1];
                int x1 = abs(x - xc), y1 = abs(y - yc);
                if (sqrt(x1 * x1 + y1 * y1) <= r)
                    count++;
            }
            res.emplace_back(count);
        }
        return res;
    }
};