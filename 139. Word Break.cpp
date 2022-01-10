class Solution {
public:
    unordered_map<int,bool> m;
    bool helper(string &s,unordered_set<string> &wordDict,int i) {
        // cout << i << endl;
        if(i>=s.size()) return true;
        if(m.find(i)!=m.end()) return m[i];
        bool res = false;
        for(int j=1;j+i<=s.size();j++) {
            string sub = s.substr(i,j);
            if(wordDict.find(sub)!=wordDict.end()) {
                if(helper(s,wordDict,i+j)) {
                    m[i] = true;
                    return true;
                }
            }
        }
        m[i] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> ss(wordDict.begin(),wordDict.end());
        return helper(s,ss,0);
    }
};