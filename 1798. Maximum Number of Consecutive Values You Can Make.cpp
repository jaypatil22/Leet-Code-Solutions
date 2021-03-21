class Solution
{
public:
    int getMaximumConsecutive(vector<int> &coins)
    {
        sort(coins.begin(), coins.end());
        int res = 0;
        for (int c : coins)
        {
            if (c <= res + 1)
            {
                res += c;
            }
        }
        return res + 1;
    }
};