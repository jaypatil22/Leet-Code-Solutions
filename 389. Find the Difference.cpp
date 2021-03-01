class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = 0;
        for(auto a : s) {
            res ^= a;
        }
        for(auto a : t) {
            res ^= a;
        }
        char b = (char)res;
        return b;
    }
};
