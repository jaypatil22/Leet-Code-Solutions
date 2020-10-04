class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int pos = 1,prev = nums[0];
        for(int i =1;i<nums.size();i++) {
            if(nums[i] != prev) {
                nums[pos] = nums[i];
                prev = nums[i];
                pos++;
            }
        }
        return pos;
    }
};
