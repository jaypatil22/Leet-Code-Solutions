class Solution
{
    long long modpow(long long base, int exp, long long mod)
    {
        long long result = 1;
        for (; exp > 0; exp >>= 1)
        {
            result = (result * ((exp & 1) ? base : 1)) % mod;
            base = base * base % mod;
        }
        return result;
    }

public:
    int maxNiceDivisors(int n)
    {
        vector<int> dp = {0, 1, 2, 3, 4, 6};
        long long mod = 1e9 + 7;
        return n < 6 ? dp[n] : dp[3 + n % 3] * modpow(3, n / 3 - 1, mod) % mod;
    }
};