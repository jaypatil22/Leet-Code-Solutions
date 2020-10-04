class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int n = nums.size();
        int imin = res,imax = res;
        for(int i =1;i<n;i++) {
            if(nums[i] < 0)
                swap(imax,imin);
            imax = max(nums[i],nums[i]*imax);
            imin = min(nums[i],nums[i]*imin);

            res = max(res,imax);
        }
        return res;
    }
};
