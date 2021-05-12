class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (int i = 0; i < n; i++)
        {
            heap.push({nums[i], i});
        }
        long long sum = 0;
        for (int i = 1; i <= right; i++)
        {
            auto a = heap.top();
            heap.pop();
            if (i >= left)
            {
                sum += a.first;
                sum %= 1000000007;
            }
            if (a.second + 1 < n)
            {
                heap.push({a.first + nums[a.second + 1], a.second + 1});
            }
        }
        return sum;
    }
};