class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return 0;
        int left = 0,right = nums.size()-1;

        while(left < right) {
            int mid = (left+right)/2;
            if(nums[mid] == target)
                return mid;
            else if(target > nums[mid]) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        if(target > nums[left])
            return left+1;
        else
            return left;
    }
};
