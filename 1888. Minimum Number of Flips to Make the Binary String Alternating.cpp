class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;
        string s1 = "",s2="";
        for(int i=0;i<s.size();i++) {
            s1 += i&1 ? '1' : '0';
            s2 += i&1 ? '0' : '1';
        }
        int res = INT_MAX,r1=0,r2=0;
        for(int i=0;i<s.size();i++) {
            if(s1[i]!=s[i]) r1++;
            if(s2[i]!=s[i]) r2++;
            if(i>=n) {
                if(s1[i-n]!=s[i-n]) --r1;
                if(s2[i-n]!=s[i-n]) --r2;
            }
            if(i>=n-1) res = min(res,min(r1,r2));
        }
        return res;
    }
};