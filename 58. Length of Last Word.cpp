class Solution {
public:
    int lengthOfLastWord(string s) {
        int res =0,prev = 0;
        for(char c : s) {
            if(c == ' ') {
                if(res != 0)
                    prev = res;
                res = 0;
            } else {
                res++;
            }
        }
        if(res == 0)
            return prev;
        return res;
    }
};
