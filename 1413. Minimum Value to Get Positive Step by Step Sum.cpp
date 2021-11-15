class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int res = 0;
        for(int i=1;i<nums.size();i++) {
            nums[i] += nums[i-1];
        }
        for(int i=0;i<nums.size();i++) {
            if(nums[i] < res) {
                res = nums[i];
            }
        }
        return -res +1;
    }
};