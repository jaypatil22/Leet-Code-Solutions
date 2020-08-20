class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() < 1)
            true;
        string a="";
        for(char b : s) {
            if(isalpha(b) || isdigit(b)) {
                a += char(tolower(b));
            }
        }
        string rev(a.rbegin(),a.rend());
        if(a == rev)
            return true;
        return false;
    }
};
