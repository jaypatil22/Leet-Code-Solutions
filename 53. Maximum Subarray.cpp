class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ma = INT_MIN,current = 0;
        for(int i=0;i<nums.size();i++) {
            current += nums[i];
            if(current > ma) {
                ma = current;
            }
            if(current < 0) {
                current = 0;
            }
        }
        return ma;
    }
};