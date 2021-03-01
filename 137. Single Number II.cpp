class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        vector<int> m(32, 0);
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if ((nums[j] >> i) & 1)
                {
                    m[i]++;
                }
            }
            res |= (m[i] % 3) << i;
        }
        return res;
    }
};