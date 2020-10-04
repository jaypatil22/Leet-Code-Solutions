class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
            return 0;
        if(haystack.size() == 0)
            return -1;
        if(needle.size() > haystack.size())
            return -1;
        if(haystack == needle)
            return 0;
        int ptr=0;
        for(int i =0;i<=haystack.size()-needle.size();i++) {
            for(int j = i;j<i+needle.size();j++) {
                if(needle[j-i] != haystack[j]) {
                    break;
                }
                if(j == i+needle.size()-1)
                    return i;

            }
        }
        return -1;
    }
};
