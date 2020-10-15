class Solution {
public:
    int countOdds(int low, int high) {
        int res = (high-low)/2;
        if(low%2 || high%2)
            res++;
        return res;
    }
};
