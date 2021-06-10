class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res = INT_MIN;
        for(int i=0,j=nums.size()-1;i<nums.size()/2;i++,j--) {
            int sum = nums[i]+nums[j];
            if(sum>res) {
                res = sum;
            }
        }
        return res;
    }
};