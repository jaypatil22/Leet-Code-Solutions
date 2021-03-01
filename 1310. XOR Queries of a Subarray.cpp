class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> res;
        vector<int> xr = arr;
        for (int i = 1; i < arr.size(); i++)
        {
            xr[i] ^= xr[i - 1];
        }
        for (int i = 0; i < queries.size(); i++)
        {
            int r;
            if (queries[i][0])
            {
                r = xr[queries[i][1]] ^ xr[queries[i][0] - 1];
            }
            else
            {
                r = xr[queries[i][1]];
            }
            res.emplace_back(r);
        }
        return res;
    }
};