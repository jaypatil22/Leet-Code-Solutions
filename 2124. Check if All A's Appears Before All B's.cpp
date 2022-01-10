class Solution {
public:
    bool checkString(string s) {
        bool flag = 0;
        for(char &a : s) {
            if(a=='b') flag = 1;
            else if(flag) return false;
        }
        return true;
    }
};