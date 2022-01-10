class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> m(n,-1);
        vector<vector<int>> r(n);
        for(int i=0;i<n;i++) r[favorite[i]].push_back(i);
        
        function<int(int)> dfs = [&](int u)->int {
            if(m[u]!=-1) return m[u];
            int ans = 0;
            for(int &v : r[u]) ans = max(ans,dfs(v));
            return m[u] = 1 + ans;
        };
        int ans = 0, free = 0;
        for(int i=0;i<n;i++) {
            if(m[i]!=-1) continue;
            if(favorite[favorite[i]]==i) {
                m[i] = m[favorite[i]] = 0;
                int a= 0,b=0;
                for(int &v : r[i]) {
                    if(v==favorite[i]) continue;
                    a = max(a,dfs(v));
                }
                for(int &v : r[favorite[i]]) {
                    if(v==i) continue;
                    b = max(b,dfs(v));
                }
                free += a + b+ 2;
            }
        }
        function<tuple<int,int,bool>(int)> dfs2 = [&](int u)->tuple<int,int,bool> {
            if(m[u]!=-1) return {u, m[u], false};
            m[u] = 0;
            auto [entryPoint,depth,cycleVisited] = dfs2(favorite[u]);
            if(cycleVisited) {
                return {entryPoint,depth,true};
            }
            m[u] = depth+1;
            return {entryPoint,m[u],u==entryPoint};
        };
        for(int i=0;i<n;i++) {
            if(m[i]!=-1) continue;
            auto [entryPoint,depth,cycleVisited] = dfs2(i);
            if(cycleVisited) ans = max(ans,depth);
        }
        return max(free,ans);
    }
};