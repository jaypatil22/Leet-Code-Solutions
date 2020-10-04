class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int last = nums[nums.size()-1],less = 0;
        bool flag = 0;
        vector<int> copy= nums;
        int i = 0;
        for(i=nums.size()-2;i>=0;i--) {
            if(nums[i] < nums[i+1]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            reverse(nums.begin(),nums.end());
            return;
        }
        int j;
        for(j = nums.size()-1;j>i;j--) {
            if(nums[j] > nums[i])
                break;
        }
        swap(nums[i],nums[j]);
        sort(nums.begin()+i+1,nums.end());
        return ;
    }
};
