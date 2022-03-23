class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int prev = nums[1]-nums[0];
        int res = 0;
        int cnt = 0;
        for(int i=2;i<nums.size();i++) {
            int cur = nums[i] - nums[i-1];
            if(cur==prev) {
                cnt++;
            } else {
                prev = cur;
                cnt = 0;
            }
            res += cnt;
        }
        return res;
    }
};