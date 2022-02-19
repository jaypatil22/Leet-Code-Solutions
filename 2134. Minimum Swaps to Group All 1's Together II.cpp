class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int res = INT_MAX;
        int ones = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) ones++;
        }
        if(ones >= nums.size()-1) return 0;
        int zeroes = 0,start = 0;
        for(int i=0;i<ones;i++) {
            if(nums[i]==0) zeroes++;
        }
        res = zeroes;
        for(int end = ones;start<nums.size();start++,end++) {
            if(nums[end%(int)nums.size()] == 0) zeroes++;
            if(nums[start]==0) zeroes--;
            res = min(res,zeroes);
        }
        return res;
    }
};