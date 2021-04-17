class Solution
{
public:
    string removeDuplicates(string S)
    {
        string res;
        for (char c : S)
        {
            if (res.size())
            {
                if (res[res.size() - 1] == c)
                {
                    res.pop_back();
                    continue;
                }
            }
            res.push_back(c);
        }
        return res;
    }
};