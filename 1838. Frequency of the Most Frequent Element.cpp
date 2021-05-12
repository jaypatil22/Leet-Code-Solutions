class Solution
{
public:
    int maxFrequency(vector<int> &nums, long long k)
    {
        long long i = 0, j = 0, res = 1, sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (k < ((i - j + 1) * nums[i]) - sum)
            {
                sum -= nums[j];
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};