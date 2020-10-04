#include <climits>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        long long res=nums[0];
        vector<int> sub(nums.size());
        sub[0] = nums[0];
        for(int i =1;i<nums.size();i++) {
           sub[i] = nums[i] + (sub[i-1] > 0 ? sub[i-1] : 0);
            if(sub[i] > res)
                res= sub[i];

        }

        return res;
    }
};
