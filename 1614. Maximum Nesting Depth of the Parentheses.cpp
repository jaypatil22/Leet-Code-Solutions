class Solution {
public:
    int maxDepth(string s) {
        int max = 0,cur=0;
        for(auto a : s) {
            if(a == '(') {
                cur++;
                if(cur>max)
                    max = cur;
            } else if(a == ')') {
                cur--;
            }
        }
        return max;
    }
};
