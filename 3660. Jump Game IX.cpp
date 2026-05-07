class Solution {
public:
    void process(vector<int>& nums, int r, int rightMin, int rightMax, vector<int>& dp, vector<pair<int, int>>& prefixMax) {
        auto [pMax, pivot] = prefixMax[r];

        int currMax = pMax <= rightMin ? pMax : rightMax;
        int nextRightMin = min(pMax, rightMin);
        for(int i=pivot; i<=r;i++) {
            dp[i] = currMax;
            if(nextRightMin > nums[i]) nextRightMin = nums[i];
        }
        if(pivot == 0) return;
        process(nums, pivot-1, nextRightMin, currMax, dp, prefixMax);
    }
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        vector<pair<int, int>> prefixMax(n);
        pair<int, int> prev = {INT_MIN, -1};
        for(int i=0;i<n;i++) {
            if(nums[i] > prev.first) {
                prev = {nums[i], i};
            }
            prefixMax[i] = prev;
        }
        process(nums, n-1, INT_MAX, 0, dp, prefixMax);
        return dp;
    }
};