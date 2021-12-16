class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        unordered_map<int,set<int>> m;
        for(int i=0;i<edges.size();i++) {
            m[edges[i][0]].insert(edges[i][1]);
            m[edges[i][1]].insert(edges[i][0]);
        }
        
        vector<int> leaves;
        for(int i=0;i<n;i++) {
            if(m[i].size()==1) leaves.push_back(i);
        }
        while(n > 2) {
            n -= leaves.size();
            vector<int> nleaves;
            for(int i: leaves) {
                int j = *m[i].begin();
                m[j].erase(m[j].find(i));
                if(m[j].size()==1) nleaves.push_back(j);
            }
            leaves = nleaves;
        }
        return leaves;
    }
};