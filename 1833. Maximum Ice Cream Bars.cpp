class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        long long cost = 0, res = 0;
        sort(costs.begin(), costs.end());
        for (int i = 0; i < costs.size(); i++)
        {
            cost += costs[i];
            if (cost <= coins)
                res++;
        }
        return res;
    }
};