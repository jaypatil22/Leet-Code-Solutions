class Solution
{
    const int mod = 1e9 + 7;

public:
    int sumOfFlooredPairs(vector<int> &nums)
    {
        long long res = 0;
        vector<int> ps(100001);
        int max_n = *max_element(nums.begin(), nums.end());
        for (int i : nums)
        {
            ++ps[i];
        }
        vector<pair<int, int>> el;
        for (int i = 1; i <= max_n; i++)
        {
            if (ps[i])
            {
                el.push_back({i, ps[i]});
            }
            ps[i] += ps[i - 1];
        }
        for (auto &[n, cnt] : el)
        {
            for (long f = max_n / n; f > 0; f--)
            {
                res = (res + f * cnt * (ps[min((long)max_n, (f + 1) * n - 1)] - ps[f * n - 1]));
                if (res > mod)
                    res -= mod;
            }
        }
        return res;
    }
};