class Solution {
public:
    void helper(string &s, int i,vector<string> &res, vector<string> &cur) {
        if(cur.size()>4) return;
        if(i==s.size() && cur.size()==4) {
            res.push_back(cur[0]+"."+cur[1]+"."+cur[2]+"."+cur[3]);
            return;
        }
        int cnt = 1;
        while(i+cnt <= s.size() && stoi(s.substr(i,cnt)) >=0 && stoi(s.substr(i,cnt)) <= 255) {
            if(s[i]=='0' && cnt > 1) break;
            cur.push_back(s.substr(i,cnt));
            helper(s,i+cnt,res,cur);
            cur.pop_back();
            cnt++;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res,cur;
        helper(s,0,res,cur);
        return res;
    }
};