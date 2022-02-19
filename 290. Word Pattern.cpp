class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        int i=0;
        while(i<s.size()) {
            while(i<s.size() && s[i]==' ') i++;
            string cur= "";
            while(i<s.size() && s[i]!=' ') {
                cur += s[i];
                i++;
            }
            if(cur!="") v.push_back(cur);
        }
        if(v.size()!=pattern.size()) return false;
        unordered_map<char,vector<int>> m;
        for(int i=0;i<pattern.size();i++) {
            m[pattern[i]].push_back(i);
        }
        unordered_set<string> se;
        for(auto a : m) {
            string cur = "";
            for(int b : a.second) {
                if(cur=="") {
                    cur = v[b];
                    if(se.find(cur)!=se.end()) return false;
                    se.insert(cur);
                } else {
                    if(cur != v[b]) return false;
                }
            }
        }
        return true;
    }
};