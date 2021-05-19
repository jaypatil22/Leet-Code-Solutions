class Solution
{
    vector<vector<int>> edges;
    vector<int> score;

    int longest(int i)
    {
        if (score[i] > 0)
            return score[i];
        score[i] = 1;
        for (int j : edges[i])
        {
            score[i] = max(score[i], longest(j) + 1);
        }
        return score[i];
    }

public:
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        edges.clear();
        edges.resize(n);
        score.clear();
        score.resize(n);
        unordered_map<string, int> m;
        for (int i = 0; i < words.size(); i++)
        {
            m[words[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            string s = words[i];
            for (int j = 0; j < s.size(); j++)
            {
                string maybe = s.substr(0, j) + s.substr(j + 1);
                auto it = m.find(maybe);
                if (it == m.end())
                    continue;
                edges[it->second].push_back(i);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res = max(res, longest(i));
        }
        return res;
    }
};