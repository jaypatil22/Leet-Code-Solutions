#include <set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        if(s.length() == 1)
            return 1;
        set<char> ss;
        ss.insert(s[0]);
        int j=0,max =1;
        for(int i=1;i<s.length();i++) {
            if(ss.find(s[i]) == ss.end()) {
                ss.insert(s[i]);
            } else {
                while(s[j] != s[i]) {
                    ss.erase(s[j]);
                    j++;
                }
                ss.erase(s[j]);
                j++;
                ss.insert(s[i]);
            }
            if(max < ss.size())
                max = ss.size();
        }

        return max;
    }
};
