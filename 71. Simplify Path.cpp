class Solution
{
public:
    string simplifyPath(string path)
    {
        stringstream ss(path);
        vector<string> rli;
        string a;
        while (getline(ss, a, '/'))
        {
            rli.emplace_back(a);
        }
        vector<string> li;
        for (string b : rli)
        {
            if (b != "")
            {
                if (b == ".")
                {
                    continue;
                }
                else if (b == "..")
                {
                    if (!(li.empty()))
                    {
                        li.pop_back();
                    }
                }
                else if (b != "..")
                {
                    li.push_back(b);
                }
            }
        }
        string res = "";
        if (li.empty())
        {
            return "/";
        }
        else
        {
            for (string c : li)
            {
                res += "/" + c;
            }
        }
        return res;
    }
};