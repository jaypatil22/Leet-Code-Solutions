class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int l=-1,r=-1,res=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] > right) {
                l = r = i;
                continue;
            }
            if(nums[i] >= left) {
                r=i;
            }
            res += r-l;
        }
        return res;
    }
};