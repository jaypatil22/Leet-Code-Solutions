class Solution
{
public:
    int maxValue(int n, int index, int maxSum)
    {
        long long l = 0, r = maxSum, j = n - index - 1;
        long long res = 0;
        while (l < r)
        {
            long long mid = (l + r + 1) / 2;
            long long sum1 = mid * mid;
            long long sum2 = mid > index ? (mid - index) * (mid - index - 1) / 2 : 0;
            long long sum4 = mid > j ? (mid - j - 1) * (mid - j) / 2 : 0;
            long long sum = (sum1) - (sum4)-sum2;
            if (sum <= maxSum - n)
            {
                res = mid;
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        return res + 1;
    }
};