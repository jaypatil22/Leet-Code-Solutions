class Solution {
public:
    int countSegments(string s) {
        int pos = 1,res = 0;
        if(!s.size())
            return 0;
        if(s[0] != ' ')
            res++;
        while(pos < s.size()) {
            if(s[pos] != ' ' && s[pos-1] == ' ')
                res++;
            pos++;
        }
        return res;
    }
};
