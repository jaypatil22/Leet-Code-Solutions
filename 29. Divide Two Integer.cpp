class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if(dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        long dvd = labs(dividend),dvs= labs(divisor);
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        int res = 0;
        while(dvd >= dvs) {
            long temp = dvs,m=1;
            while(temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            res += m;
            dvd -= temp;
        }

        return sign * res;
    }
};
