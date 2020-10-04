class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0,right;
        sort(nums.begin(),nums.end());
        bool flag = 0;
        for(int i = 0;i<nums.size();i++) {
            if(nums[i] == val) {
                left = i;
                flag = 1;
                break;
            }
        }
        for(int i = nums.size()-1;i>=0;i--) {
            if(nums[i] == val) {
                right = i;
                break;
            }
        }
        if(flag == 0)
            return nums.size();
        if(right < nums.size()-1) {
            for(int i = right+1;i<nums.size();i++) {
                nums[left] = nums[i];
                left++;
            }
            return left;
        } else {
            return left;
        }
    }
};
