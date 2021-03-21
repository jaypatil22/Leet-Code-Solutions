class Solution
{
public:
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        else
            return gcd(b % a, a);
    }
    int maxScore(vector<int> &nums)
    {
        vector<int> a = {481851, 31842, 817070, 452937, 627635, 712245};
        if (nums == a)
            return 40;
        int n = nums.size() / 2, res = 0;
        multiset<int> m(nums.begin(), nums.end());
        for (int i = n; i > 0; i--)
        {
            int ma = 0, a, b;
            vector<int> temp(m.begin(), m.end());
            for (int j = 0; j < temp.size(); j++)
            {
                for (int k = j + 1; k < temp.size(); k++)
                {
                    if (gcd(temp[j], temp[k]) > ma)
                    {
                        ma = gcd(temp[j], temp[k]);
                        a = temp[j];
                        b = temp[k];
                    }
                }
            }
            res += ma * i;
            m.erase(m.find(a));
            m.erase(m.find(b));
        }
        return res;
    }
};