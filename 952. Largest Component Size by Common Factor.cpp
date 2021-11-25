class Solution {
public:
    int find(vector<int> &parent, int a) {
        if(parent[a]==-1) return a;
        parent[a] = find(parent,parent[a]);
        return parent[a];
    }
    void uni(vector<int> &parent, int a, int b) {
        int c = find(parent,a);
        int d = find(parent,b);
        if(c != d) parent[d] = c;
    }
    int largestComponentSize(vector<int>& nums) {
        vector<int> parent(100001,-1);
        for(int a : nums) {
            for(int i=2;i<=sqrt(a);i++) {
                if(a%i==0) {
                    uni(parent,a,i);
                    uni(parent,a,a/i);
                }
            }
        }
        int res = 0;
        unordered_map<int,int> m;
        for(int a : nums) {
            int b = find(parent,a);
            m[b]++;
            if(m[b] > res) res = m[b];
        } 
        return res;
    }
};