class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res = nums[nums.size()-1]-nums[0];
        for(int i=0;i<nums.size()-1;i++) {
            // if(nums[i+1] >= k) {
                int mi = min(nums[i+1]-k,nums[0]+k);
                int ma = max(nums[i]+k,nums[nums.size()-1]-k);
                res = min(res,ma-mi);
            // }
        }
        return res;
    }
};