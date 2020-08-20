#include <climits>
class Solution {
public:
    int reverse(int x) {
        long long int res =0;
        long long mul = 1;
        bool flag = 0;
        if(x < 0)
            flag = 1;
        long long b = x;
        while(b!=0) {
            res = (res*10) + (b%10);
            mul *= 10;
            b /= 10;
        }
        return (res>=(INT_MAX) ||(res <INT_MIN))?0:res;

    }
};
