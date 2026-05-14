class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i=0;i<size-1;i++) {
            if(nums[i] != i+1) return false;
        }
        return nums[size-1] == size-1;
    }
};