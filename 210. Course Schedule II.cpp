class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> v(numCourses);
        vector<bool> todo(numCourses, false), done(numCourses, false);
        vector<int> order;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            v[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (!done[i] && !helper(v, todo, done, i, order))
                return {};
        }
        reverse(order.begin(), order.end());
        return order;
    }

    bool helper(vector<vector<int>> &g, vector<bool> &todo, vector<bool> &done, int node, vector<int> &order)
    {
        if (todo[node])
            return false;
        if (done[node])
            return true;

        todo[node] = done[node] = true;
        for (int v : g[node])
        {
            if (!helper(g, todo, done, v, order))
                return false;
        }
        order.push_back(node);
        todo[node] = false;
        return true;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> m(numCourses);
        vector<int> indeg(numCourses,0);
        for(int i=0;i<prerequisites.size();i++) {
            m[prerequisites[i][1]].insert(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++) {
            if(indeg[i]==0) q.push(i);
        }
        
        vector<int> res;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            
            if(m[node].size()) {
                for(int a : m[node]) {
                    indeg[a]--;
                    if(indeg[a]==0) q.push(a);
                }
            }
        }
        if(res.size()==numCourses) return res;
        else return {};
    }
};