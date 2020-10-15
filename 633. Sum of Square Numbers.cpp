class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c < 0)
            return false;
        int left = 0,right = (int)sqrt(c);
        while(left <= right) {
            long long t = (long long)left*left + right*right;
            if(t <c) {
                left++;
            } else if(t > c) {
                right--;
            } else {
                return true;
            }
        }
        return false;
    }
};
