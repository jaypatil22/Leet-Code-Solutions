class Solution {
public:
    class UnionFind {
        public:
        vector<int> id;
        UnionFind(int n) {
            for(int i=0;i<n;i++) {
                id.push_back(i);
            }
        }
        
        int find(int a) {
            return a == id[a] ? a : (id[a] = find(id[a]));
        }
        
        void connect(int a, int b) {
            id[a] = find(b);
        }
        bool connected(int a, int b) {
            return id[a] == id[b];
        }
    };
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        UnionFind uf = UnionFind(n);
        vector<bool> res;
        
        for(auto &a : requests) {
            int p = uf.find(a[0]), q = uf.find(a[1]);
            int valid = true;
            if(!uf.connected(p,q)) {
                for(auto &b : restrictions) {
                    int x = uf.find(b[0]), y = uf.find(b[1]);
                    if((x==p && y==q) || (x==q && y==p)) {
                        valid = false;
                        break;
                    }
                }
            }
            res.push_back(valid);
            if(valid) uf.connect(p,q);
        }
        return res;
    }
};