class Solution
{
public:
    string sortSentence(string s)
    {
        vector<string> a(10);
        int i = 0;
        while (i < s.size())
        {
            string b = "";
            while (i < s.size() && s[i] != ' ')
            {
                b += s[i];
                i++;
            }
            i++;
            int pos = b[b.size() - 1] - '0';
            b.erase(b.size() - 1, 1);
            a[pos] = b;
        }
        string res = "";
        for (int i = 1; i < 10; i++)
        {
            if (a[i] != "")
            {
                res += a[i] + ' ';
            }
        }
        res.erase(res.size() - 1, 1);
        return res;
    }
};