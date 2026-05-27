class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool l[26]={0}, u[26]={0};
        int res = 0;
        for(char a : word) {
            if(a <= 'z' && a >= 'a') {
                l[a-'a'] = 1;
            } else {
                u[a-'A'] = 1;
            }
        }
        for(int i=0;i<26;i++) {
            if(l[i] && u[i]) res++;
        }
        return res;
    }
};