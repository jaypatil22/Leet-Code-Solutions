class Solution
{
public:
    int maxPower(string s)
    {
        char pre, current;
        int res = 0, curr = 1;
        pre = s[0];
        for (int i = 1; i < s.size(); i++)
        {
            if (pre == s[i])
            {
                curr++;
            }
            else
            {
                if (curr > res)
                {
                    res = curr;
                }
                pre = s[i];
                curr = 1;
            }
        }
        if (curr > res)
            res = curr;
        return res;
    }
};