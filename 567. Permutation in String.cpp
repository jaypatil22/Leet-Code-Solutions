class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> cnt(26,0);
        for(char c : s1) {
            cnt[c-'a']++;
        }
        vector<int> scnt(26,0);
        for(int i=0;i<s1.size()-1;i++) {
            scnt[s2[i]-'a']++;
        }
        for(int start = 0, end = s1.size()-1;end < s2.size();start++,end++) {
            scnt[s2[end]-'a']++;
            int flag = 1;
            for(int i=0;i<26;i++) {
                if(cnt[i]!=scnt[i]) {
                    flag = 0;
                    break;
                }
            }
            if(flag) return true;
            scnt[s2[start]-'a']--;
        }
        return false;
    }
};