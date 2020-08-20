#include <climits>
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        stringstream ss;
        ss << x;
        string s;
        ss >> s;
        string reverse(s.rbegin(),s.rend());
        ss.clear();
        ss << reverse;
        long long r;
        ss >> r;
        if(r > INT_MAX)
            return false;
        if(x == r)
            return true;
        else
            return false;
    }
};
