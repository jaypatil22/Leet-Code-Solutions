class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1,0);
        for(int i=0;i<parent.size();i++) {
            parent[i] = i;
        }
        for(auto edge : edges) {
            int n1 = edge[0];
            int n2 = edge[1];
            while(n1 != parent[n1]) n1 = parent[n1];
            while(n2 != parent[n2]) n2 = parent[n2];
            if(n1 == n2) return edge;
            else {
                parent[n1] = n2;
            }
        }
        return {};
    }
};