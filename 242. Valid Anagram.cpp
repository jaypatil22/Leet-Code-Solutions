class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        vector<int> a(26, 0), b(26, 0);
        for (char c : s)
        {
            a[c - 'a']++;
        }
        for (char c : t)
        {
            b[c - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (b[i] != a[i])
                return false;
        }
        return true;
    }
};