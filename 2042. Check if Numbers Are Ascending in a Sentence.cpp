class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev= 0;
        int i=0;
        while(i<s.size()) {
            while(i<s.size() && !isdigit(s[i])) {
                i++;
            }
            if(i>=s.size()) break;
            int num = 0;
            while(i<s.size() && isdigit(s[i])) {
                num = num*10+(s[i]-'0');
                i++;
            }
            if(prev >= num) return false;
            prev = num;
        }
        return true;
    }
};