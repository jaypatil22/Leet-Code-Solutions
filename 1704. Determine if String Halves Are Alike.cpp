class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        set<char> se({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        int h2 = 0, h1 = 0, i;
        for (i = 0; i < s.size() / 2; i++)
        {
            if (se.find(s[i]) != se.end())
            {
                h1++;
            }
        }
        for (; i < s.size(); i++)
        {
            if (se.find(s[i]) != se.end())
            {
                h2++;
            }
        }

        return h1 == h2;
    }
};