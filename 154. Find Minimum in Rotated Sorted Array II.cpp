class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int l = 0, h = nums.size()-1;
        while(l<h) {
            int mid = l + (h-l)/2;
            
            if(nums[mid] > nums[h]) {
                l = mid+1;
            } else if(nums[mid] < nums[h]) {
                h = mid;
            } else {
                h--;
            }
        }
        return nums[l];
    }
};