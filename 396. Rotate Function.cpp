class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        vector<int> prefixSum(nums.begin(), nums.end());
        int sum = 0, res = 0, prev = 0;
        for(int i=0;i<n;i++) {
            sum += nums[i];
            prev += nums[i]*i;
        }
        res = prev;
        for(int i=1;i<n;i++) {
            int n_prev = (prev - (sum - nums[i-1])) + nums[i-1]*(n-1);
            res = max(res, n_prev);
            prev = n_prev;
        }
        return res;
    }
};