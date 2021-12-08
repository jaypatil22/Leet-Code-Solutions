class Solution {
public:
    unordered_map<string,bool> m;
    bool isScramble(string s1, string s2) {
        if(m.find(s1+s2)!=m.end()) return m[s1+s2];
        if(s1==s2) {
            m[s1+s2] = true;
            return true;
        }
        int cnt[26]={0};
        for(int i=0;i<s1.size();i++) {
            cnt[s1[i]-'a']++;
            cnt[s2[i]-'a']--;
        }
        for(int i=0;i<26;i++) {
            if(cnt[i]!=0) {
                m[s1+s2] = false;
                return false;
            }
        }
        if(s1.size()<=3) return true;
        for(int i=1;i<s1.size();i++) {
            
            if(isScramble(s1.substr(i),s2.substr(i)) && isScramble(s1.substr(0,i),s2.substr(0,i))) {
                m[s1+s2] = true;
                return true;
            }
                
            if(isScramble(s1.substr(0,i),s2.substr(s1.size()-i)) && isScramble(s1.substr(i),s2.substr(0,s1.size()-i))) {
                m[s1+s2] = true;
                return true;
            }
        }
        m[s1+s2] = false;
        return false;
    }
};