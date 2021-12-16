class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) {
        id.resize(n+1);
        for(int i=0;i<=n;i++) id[i] = i;
    }
    void connect(int a, int b) {
        id[find(b)] = find(a);
    }
    int find(int a) {
        return a == id[a] ? a : (id[a] = find(id[a]));
    }
    bool connected(int a,int b) {
        return find(a)==find(b);
    }
    void reset(int a) {
        id[a] = a;
    }
};
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(),meetings.end(),[](vector<int>&a,vector<int> &b){return a[2] < b[2];});
        UnionFind uf = UnionFind(n);
        uf.connect(0,firstPerson);
        vector<int> ppl;
        for(int i=0;i<meetings.size();) {
            ppl.clear();
            int time = meetings[i][2];
            for(;i<meetings.size() && time == meetings[i][2];i++) {
                int first = meetings[i][0] < meetings[i][1] ? meetings[i][0] : meetings[i][1];
                int second = meetings[i][1] < meetings[i][0] ? meetings[i][0] : meetings[i][1]; 
                uf.connect(first,second);
                ppl.push_back(meetings[i][0]);
                ppl.push_back(meetings[i][1]);
            }
            for(int a : ppl) {
                if(!uf.connected(0,a)) uf.reset(a);
            }
        }
        vector<int> res;
        for(int i=0;i<=n;i++) {
            if(uf.connected(0,i)) res.push_back(i);
        }
        return res;
    }
};