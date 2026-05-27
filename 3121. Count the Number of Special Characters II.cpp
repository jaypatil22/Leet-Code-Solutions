class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool l[26]={0}, u[26]={0}, v[26] = {0}, i[26]={0};
        for(char a : word) {
            if(a <= 'z' && a>='a') {
                l[a-'a'] = 1;
                if(u[a-32-'A']) {
                    i[a-32-'A'] = 1;
                }
            } else {
                u[a-'A'] = 1;
                if(l[a+32-'a']) {
                    v[a+32-'a'] = 1;
                }
            }
        }
        int res = 0;
        for(int j=0;j<26;j++) {
            if(v[j] && !i[j]) res++;
        }
        return res;
    }
};