class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n,0);
        for(int j=1;j<n;j++) {
            for(int i=0;i<j;i++) {
                if(abs(nums[j]-nums[i]) <= target) {
                    if(i!=0 && dp[i]==0) continue;
                    dp[j] = max(dp[j], dp[i]+1);
                }
            }
        }
        for(int i : dp) {
            cout << i << " ";
        }
        return dp[n-1] == 0 ? -1 : dp[n-1];
    }
};