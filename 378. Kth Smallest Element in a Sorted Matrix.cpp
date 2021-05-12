class Solution
{
public:
    struct numCompare
    {
        bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y)
        {
            return x.first > y.first;
        }
    };
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size(), n = matrix[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, numCompare> minHeap;
        for (int i = 0; i < min(k, m); i++)
        {
            minHeap.push(make_pair(matrix[i][0], make_pair(i, 0)));
        }
        int res = 0, count = 0;
        while (!minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();
            count++;
            res = top.first;
            // cout << res << " ";
            if (count == k)
                break;
            top.second.second++;
            if (n > top.second.second)
            {
                top.first = matrix[top.second.first][top.second.second];
                minHeap.push(top);
            }
        }
        return res;
    }
};