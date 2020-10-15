class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s=="")
            return true;
        int i =0,n=s.size();
        for(auto a : t) {
            if(a == s[i])
                i++;
            if(i == n)
                return true;
        }
        return false;
    }
};
