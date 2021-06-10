class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dds(deadends.begin(),deadends.end());
        unordered_set<string> visited;
        queue<string> bfs;
        if(dds.find("0000")!=dds.end()) return -1;
        if(target == "0000") return 0;
        string init = "0000";
        visited.insert(init);
        bfs.push(init);
        int res = 0;
        while(!bfs.empty()) {
            int sz = bfs.size();
            for(int i=0;i<sz;i++) {
                string t = bfs.front();bfs.pop();
                vector<string> strs = nbrs(t);
                for(string s : strs) {
                    if(visited.find(s)!=visited.end()) continue;
                    if(s == target) return ++res;
                    if(dds.find(s)!=dds.end()) continue;
                    bfs.push(s);
                    visited.insert(s);
                }
            }
            res++;
        }
        
        return -1;
    }
    
    vector<string> nbrs(string key) {
        vector<string> res;
        for(int i=0;i<4;i++) {
            string tmp = key;
            tmp[i] = ((key[i]-'0'+1)%10) + '0';
            res.push_back(tmp);
            tmp[i] = ((key[i]-'0'-1+10)%10) + '0';
            res.push_back(tmp);
        }
        return res;
    }
};