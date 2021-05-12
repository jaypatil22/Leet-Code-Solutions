class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> sums(n - k + 1, 0), left(n - k + 1, 0), right(n - k + 1, 0);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (i >= k)
            {
                sum -= nums[i - k];
            }
            if (i >= k - 1)
            {
                sums[i - k + 1] = sum;
            }
        }
        for (int i = 0, j = 0; i < n - k + 1; i++)
        {
            if (sums[i] > sums[j])
            {
                j = i;
            }
            left[i] = j;
        }
        for (int i = n - k, j = n - k; i >= 0; i--)
        {
            if (sums[i] >= sums[j])
            {
                j = i;
            }
            right[i] = j;
        }
        sum = 0;
        vector<int> ans;
        for (int i = k; i < n - 2 * k + 1; i++)
        {
            if ((sums[left[i - k]] + sums[i] + sums[right[i + k]]) > sum)
            {
                ans = {left[i - k], i, right[i + k]};
                sum = sums[left[i - k]] + sums[i] + sums[right[i + k]];
            }
        }
        return ans;
    }
};