class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        vector<int> res, xr(nums.size());
        xr = nums;
        for (int i = 1; i < nums.size(); i++)
        {
            xr[i] ^= xr[i - 1];
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int cur = xr[i], a = 0;
            for (int j = maximumBit - 1; j >= 0; j--)
            {
                // cout << cur << "\n";

                if ((cur) & (1 << j))
                {
                }
                else
                {
                    a = 1 << j | a;
                }
            }
            res.push_back(a);
        }
        return res;
    }
};