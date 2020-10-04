class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.emplace_back(-1);
        res.emplace_back(-1);
        if(nums.size() == 1) {
            if (target == nums[0] ) {
                res[0] = 0;res[1] = 0;
            }
            return res;
        }
        int left = 0, right = nums.size()-1;
        while(left <= right) {
            int mid = (left+right)/2;
            if(nums[mid] == target) {
                int p = mid-1;
                while(p>=0 && nums[p] == target) {
                    p--;
                }

                res[0] = ++p;
                p = mid+1;
                while(p < nums.size() && nums[p] == target) {
                    p++;
                }

                res[1] = --p;
                return res;
            } else if(nums[mid] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return res;
    }
};
