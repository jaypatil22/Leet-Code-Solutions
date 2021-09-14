class Solution {
public:
    string reverseOnlyLetters(string s) {
        string t="";
        for(int i=0;i<s.size();i++) {
            if(isalpha(s[i])) {
                t += s[i];
            }
        }
        int j=t.size()-1;
        for(int i=0;i<s.size();i++) {
            if(isalpha(s[i])) {
                s[i] = t[j--];
            }
        }
        return s;
    }
};