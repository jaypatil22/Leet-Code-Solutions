class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,0);
        queue<int> q;
        
        for(int i=0;i<n;i++) {
            if(color[i]) continue;
            
            color[i] = 1;
            for(q.push(i);!q.empty();q.pop()) {
                int cur = q.front();
                
                for(int neigh : graph[cur]) {
                    // cout << cur << " " << neigh << endl;
                    if(!color[neigh]) {
                        color[neigh] = (-color[cur]);
                        q.push(neigh);
                    } else if(color[neigh]==color[cur]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};