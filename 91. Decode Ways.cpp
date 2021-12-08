class Solution {
public:
    unordered_map<int,int> m;
    int helper(string &s,int i) {
        if(i==s.size()) {
            return 1;
        }
        if(m.find(i)!=m.end()) return m[i];
        int cnt = 1;
        int res = 0;
        while(i+cnt <= s.size() && stoi(s.substr(i,cnt)) > 0 && stoi(s.substr(i,cnt)) <=26) {
            res += helper(s,i+cnt);
            cnt++;
        }
        m[i] = res;
        return res;
    }
    int numDecodings(string s) {
        // int res = 0;
        return helper(s,0);
        // return res;
    }
};