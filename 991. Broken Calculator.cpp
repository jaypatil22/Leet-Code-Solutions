class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int res = 0;
        while(startValue < target) {
            res++;
            if(target%2) {
                target++;
            } else 
                target /= 2;
        }
        res += startValue - target;
        return res;
    }
};