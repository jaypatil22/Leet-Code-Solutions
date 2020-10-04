// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long left = 1,right = n,f,t;
        while(left <= right) {
            long long mid = (left+right)/2;
            if(isBadVersion(mid)) {
                right = mid-1;
                t = mid;
            } else {
                left = mid+1;
                f = mid;
            }
        }
        return t;
    }
};
