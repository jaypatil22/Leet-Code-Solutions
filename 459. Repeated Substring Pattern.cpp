class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        for(int i =1;i<=s.size()/2;i++) {
            if(s.size()%i)
                continue;
            string sb = s.substr(0,i);
            string sub = "";
            while(sub.size()!=s.size()) {
                sub += sb;
            }
            if(sub == s)
                return true;
        }
        return false;
    }
};
