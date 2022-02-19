class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return {};
        vector<int> res;
        vector<int> a(26,0),b(26,0);
        for(char c : p) a[c-'a']++;
        for(int i=0;i<p.size()-1;i++) {
            b[s[i]-'a']++;
        }
        for(int start= 0,end = p.size()-1;start+p.size()<=s.size();start++,end++) {
            b[s[end]-'a']++;
            int flag = 1;
            for(int i=0;i<26;i++) {
                if(a[i]!=b[i]) {
                    flag = 0;
                    break;
                }
            }
            if(flag) res.push_back(start);
            b[s[start]-'a']--;
        }
        return res;
    }
};