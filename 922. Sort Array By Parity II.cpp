class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i=0,j=1,n=nums.size();
        while(i<n && j<n) {
            while(i<n && nums[i]%2 == 0) {
                i+=2;
            }
            while(j<n && nums[j]%2 ==1) {
                j+=2;
            }
            if(i<n) {
                swap(nums[i],nums[j]);
            }
        }
        return nums;
    }
};