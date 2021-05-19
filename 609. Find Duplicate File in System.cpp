class Solution
{
public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;

        for (string path : paths)
        {
            stringstream ss(path);
            string root;
            getline(ss, root, ' ');
            string file;
            while (getline(ss, file, ' '))
            {
                string name = root + "/" + file.substr(0, file.find("("));
                string data = file.substr(file.find("(") + 1, file.find(")") - file.find("(") - 1);
                m[data].push_back(name);
            }
        }
        for (auto a : m)
        {
            if (a.second.size() > 1)
            {
                res.push_back(a.second);
            }
        }
        return res;
    }
};