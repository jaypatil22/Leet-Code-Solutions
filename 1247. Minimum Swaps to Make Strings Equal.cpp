class Solution
{
public:
    int minimumSwap(string s1, string s2)
    {
        int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == s2[i])
                continue;
            if (s1[i] == 'x')
                x1++;
            else
                y1++;
            if (s2[i] == 'x')
                x2++;
            else
                y2++;
        }
        if ((x1 + x2) % 2 != 0 || (y1 + y2) % 2 != 0)
            return -1;
        int ans = x1 / 2 + y1 / 2 + (x1 % 2) * 2;
        return ans;
    }
};