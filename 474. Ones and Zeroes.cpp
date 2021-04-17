class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int dp[101][101]{0};
        for (string s : strs)
        {
            int ones = 0, zeroes = 0;
            for (char a : s)
            {
                a == '0' ? zeroes++ : ones++;
            }
            for (int i = m; i >= zeroes; i--)
            {
                for (int j = n; j >= ones; j--)
                {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeroes][j - ones]);
                }
            }
        }
        return dp[m][n];
    }
};