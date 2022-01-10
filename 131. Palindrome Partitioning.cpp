class Solution {
public:
    bool isPalin(string &s) {
        int i=0,j=s.size()-1;
        while(i<j) {
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    void helper(string &s,int i,vector<string> &cur,vector<vector<string>> &res) {
        if(i>=s.size()) {
            res.push_back(cur);
            return;
        }
        for(int j=1;j+i<=s.size();j++) {
            string sub = s.substr(i,j);
            if(isPalin(sub)) {
                cur.push_back(sub);
                helper(s,i+j,cur,res);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        helper(s,0,cur,res);
        return res;
    }
};