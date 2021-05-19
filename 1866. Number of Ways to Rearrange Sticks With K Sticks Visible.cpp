class Solution
{
    const int mod = 1e9 + 7;
    vector<vector<int>> dp;

public:
    long long helper(long long n, long long k)
    {
        if (k == 0 || k > n)
            return 0;
        if (n <= 2)
            return 1;
        if (dp[n][k] != -1)
            return dp[n][k];
        long long ans = 0;
        ans = (ans + helper(n - 1, k - 1)) % mod;
        ans = (ans + (n - 1) * helper(n - 1, k)) % mod;
        return dp[n][k] = ans;
    }
    int rearrangeSticks(int n, int k)
    {
        dp.resize(n + 1, vector<int>(k + 1, -1));
        long long res = helper(n, k);
        if (res > mod)
            res -= mod;
        return res;
    }
};