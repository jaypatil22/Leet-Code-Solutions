class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
        for(int a : nums) {
            if(a > max1) {
                max3 = max2;
                max2 = max1;
                max1 = a;
            } else if(a > max2) {
                max3 = max2;
                max2 = a;
            } else if(a >max3) {
                max3 = a;
            }

            if(a < min1) {
                min2 = min1;
                min1 = a;
            } else if(a < min2) {
                min2 = a;
            }
        }
        int res = max(max3*max2*max1,min1*min2*max1);
        return res;
    }
};
