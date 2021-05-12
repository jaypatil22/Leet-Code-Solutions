class Solution {
public:
    
    void tarjan(vector<vector<int>> &res,vector<vector<int>> &g,vector<int> &id,vector<int> &low,int u,vector<bool> &vi,vector<int> &parent) {
        static int id1 = 0;
        vi[u]=true;
        id[u] = low[u] = ++id1;
        for(int v : g[u]) {
            if(!vi[v]) {
                parent[v]=u;
                tarjan(res,g,id,low,v,vi,parent);
                low[u] = min(low[u],low[v]);
                if(id[u]<low[v]) {
                    res.emplace_back(vector<int>({u,v}));
                }
            } else if(v != parent[u]){
                low[u] = min(id[v],low[u]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int> > res;
        vector<vector<int> > g(n,vector<int>());
        vector<int> id(n,-1),low(n,INT_MAX),parent(n,-1);
        vector<bool> vi(n,false);
        for(auto a : connections) {
            g[a[0]].emplace_back(a[1]);
            g[a[1]].emplace_back(a[0]);
        }
        for(int i=0;i<n;i++) {
            if(!vi[i]) {
                tarjan(res,g,id,low,i,vi,parent);
            }
        }
        return res;
    }
};