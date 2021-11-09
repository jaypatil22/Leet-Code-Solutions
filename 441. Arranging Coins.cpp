class Solution {
public:
    int arrangeCoins(int n) {
        long long l = 0, r = INT_MAX;
        while(l<=r) {
            long long mid = l + (r-l)/2;
            long long coins = (mid*mid+mid)/2;
            if(coins <= n) {
                l = mid + 1;
            } else {
                r = mid-1;
            }
        }
        return r;
    }
};