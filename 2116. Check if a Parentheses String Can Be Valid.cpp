class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()&1) return false;
        auto validate = [&](char op) {
            int wild = 0, bal = 0;
            int start = op=='(' ? 0 : s.size()-1,dir = op=='('?1:-1;
            for(int i=start;i>=0 && i<s.size() && wild + bal >=0;i+= dir) {
                if(locked[i]=='1') {
                    bal += op==s[i] ? 1 : -1;
                } else {
                    wild++;
                }
            }
            return abs(bal) <= wild;
        };
        
        return validate('(') and validate(')');
    }
};