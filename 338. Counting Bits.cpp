class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.emplace_back(0);
        if(num ==0)
            return res;
        int i= 1,c=0;
        int r= 1;
        while(num >= i) {
            if(i == r) {
                res.emplace_back(1);
                r *= 2;
                c=1;
            } else {
                res.emplace_back(1+res[c]);
                c++;
            }
            i++;
        }
        return res;
    }
};
