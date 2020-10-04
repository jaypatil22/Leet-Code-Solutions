class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res,min = 10000;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++) {
            if(i>0 && nums[i] == nums[i-1]) continue;
            int l = i+1,r= nums.size()-1;
            bool flag = 0;
            while(l<r) {
                int sum = nums[i]+nums[l]+nums[r];
                if (sum == target) return target;
                if(abs(sum - target) < min) {
                    res = sum;
                    min = abs(sum-target);
                }
                if(sum < target) {
                    flag = 0;
                    l++;
                } else {
                    flag = 1;
                    r--;
                }
            }
        }
        return res;
    }
};
