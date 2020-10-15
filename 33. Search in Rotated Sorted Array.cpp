class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<r) {
            int mid = (l+r)/2;
            if(nums[mid] > nums[r]) l = mid+1;
            else
                r=mid;
        }
        int rot = l;
        l=0;r=nums.size()-1;
        while(l <= r) {
            int mid = (l+r)/2;
            int real = (mid +rot)%nums.size();
            if(nums[real] == target) return real;
            else if(nums[real] < target) l = mid+1;
            else r= mid-1;
        }
        return -1;
    }
};
