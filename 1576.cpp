class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for(int i =0;i<n;i++) {
            if(s[i] == '?') {
                for(int j = 0;j<26;j++) {
                    if(i==0) {
                        if(j+'a' != s[i+1]){
                            s[i] = j+'a';
                            break;
                        } else {
                            continue;
                        }
                    }
                    if(i==n-1) {
                        if(j+'a' != s[i-1]){
                            s[i] = j+'a';
                            break;
                        } else {
                            continue;
                        }
                    }
                    if(j+'a' != s[i-1] && j+'a' != s[i+1]) {
                        s[i] = j+'a';
                        break;
                    }
                }
            }
        }
        return s;
    }
};
