class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        unordered_set<char> r1, r2, r3;
        vector<string> res;
        r1.insert({'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'});
        r2.insert({'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'});
        r3.insert({'z', 'x', 'c', 'v', 'b', 'n', 'm'});
        for (string a : words)
        {
            if (r1.find(tolower(a[0])) != r1.end())
            {
                for (char b : a)
                {
                    if (r1.find(tolower(b)) == r1.end())
                    {
                        goto here;
                    }
                }
                res.emplace_back(a);
            }
            else if (r2.find(tolower(a[0])) != r2.end())
            {
                for (char b : a)
                {
                    if (r2.find(tolower(b)) == r2.end())
                    {
                        goto here;
                    }
                }
                res.emplace_back(a);
            }
            else if (r3.find(tolower(a[0])) != r3.end())
            {
                for (char b : a)
                {
                    if (r3.find(tolower(b)) == r3.end())
                    {
                        goto here;
                    }
                }
                res.emplace_back(a);
            }
        here:;
        }
        return res;
    }
};