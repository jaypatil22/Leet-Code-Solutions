class Solution
{
public:
    int titleToNumber(string s)
    {
        int res = 0;
        long long mul = 1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            res += mul * (s[i] - 64);
            mul *= 26;
        }
        return res;
    }
};