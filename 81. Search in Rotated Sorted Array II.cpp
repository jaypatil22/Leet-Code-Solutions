class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 1) {
            if(target ==  nums[0])
                return true;
            else
                return false;
        }
        int left =0,right = nums.size()-1,mid= 0;

        while(left <= right) {
            while(left<right && nums[left] == nums[left+1])
                left++;
            while(left<right && nums[right] == nums[right-1])
                right--;
            mid = left + ((right-left) /2);
            if(nums[mid] == target) return true;

            if(nums[mid] > target) {
                if(nums[left] > nums[mid] || nums[left] <= target)  {
                    right = mid -1;
                } else {
                    left = mid +1;
                }
            } else {
                if(nums[left] <= nums[mid] || nums[left] > target) {
                    left =  mid +1;
                } else {
                    right = mid-1;
                }
            }
        }
        return false;
    }
};
