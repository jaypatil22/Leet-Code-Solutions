class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        int prev = -1,cur = -1;
        for(int i=0;i<s.size();i++) {
            m[s[i]] = i;
        }
        vector<int> res;
        for(int i=0;i<s.size();i++) {
            cur = max(cur,m[s[i]]);
            if(cur == i) {
                res.push_back(cur-prev);
                prev = i;
            }
        }
        return res;
    }
};