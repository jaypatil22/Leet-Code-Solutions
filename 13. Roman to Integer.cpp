#include <cstring>
class Solution {
public:
    int romanToInt(string s) {
        int roman[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string rc[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int res = 0, i =0,r=12;
        while(i< s.size()) {
            if(strncmp(&s[i],&rc[r][0],rc[r].size()) == 0) {
                res += roman[r];
                i += rc[r].size();
            } else {
                r--;
            }
        }
        return res;
    }
};
