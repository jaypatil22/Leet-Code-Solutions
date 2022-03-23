class Solution {
public:
    vector<vector<int>> cache;
    int endingMask;
    int dp(int node,int mask,vector<vector<int>> &graph) {
        if(cache[node][mask]!=0) return cache[node][mask];
        if((mask & (mask-1)) == 0) return 0;
        cache[node][mask] = INT_MAX-1;
        for(int neigh : graph[node]) {
            if((mask & (1<<neigh)) != 0) {
                int av = dp(neigh,mask,graph);
                int nv = dp(neigh,mask^(1<<node),graph);
                int b = min(av,nv);
                cache[node][mask] = min(cache[node][mask],1+b);
            }
        }
        return cache[node][mask];
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        endingMask = (1<<n)-1;
        cache = vector<vector<int>>(n+1,vector<int>(endingMask+1,0));
        int res = INT_MAX;
        for(int i=0;i<n;i++) {
            res = min(res,dp(i,endingMask,graph));
        }
        return res;
    }
};