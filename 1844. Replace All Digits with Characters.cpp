class Solution
{
public:
    string replaceDigits(string s)
    {
        if (s.size() <= 1)
        {
            return s;
        }
        for (int i = 1; i < s.size(); i += 2)
        {
            s[i] = s[i - 1] + (s[i] - '0');
        }
        return s;
    }
};