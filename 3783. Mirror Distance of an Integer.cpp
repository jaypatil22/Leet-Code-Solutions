class Solution {
public:
    int mirrorDistance(int n) {
        int reverse = 0;
        int copy_n = n;
        while(copy_n) {
            reverse *= 10;
            reverse += copy_n%10;
            copy_n /= 10;
        }
        return abs(n-reverse);
    }
};