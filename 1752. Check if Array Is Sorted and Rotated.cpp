class Solution {
public:
    bool check(vector<int>& nums) {
        int a = 1;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] > nums[(i+1)%nums.size()] && a == 1) a--;
            else if(nums[i] > nums[(i+1)%nums.size()] && a == 0) return false;
        }
        return true;
    }
};