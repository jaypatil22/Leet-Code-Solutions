class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> v(numCourses);
        vector<bool> todo(numCourses, false), done(numCourses, false);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            v[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (!done[i] && !helper(v, todo, done, i))
                return false;
        }
        return true;
    }

    bool helper(vector<vector<int>> &g, vector<bool> &todo, vector<bool> &done, int node)
    {
        if (todo[node])
            return false;
        if (done[node])
            return true;

        todo[node] = done[node] = true;
        for (int v : g[node])
        {
            if (!helper(g, todo, done, v))
                return false;
        }
        todo[node] = false;
        return true;
    }
};