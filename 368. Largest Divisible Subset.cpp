class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int flag = 1;
        if(nums[0]==1) {
            flag = 0;
        } else {
            nums.push_back(1);
            sort(nums.begin(),nums.end());
        }
        int dp[nums.size()][2];
        for(int i=nums.size()-1;i>=0;i--) {
            dp[i][0] = 0;
            dp[i][1] = i;
            for(int j=i+1;j<nums.size();j++) {
                if(nums[j]%nums[i]==0) {
                    if(dp[i][0] < dp[j][0]) {
                        dp[i][0] = dp[j][0];
                        dp[i][1] = j;
                    }
                }
            }
            dp[i][0]++;
        }
        int i=0;
        vector<int> res;
        res.push_back(nums[i]);
        while(dp[i][1]!=i) {
            i = dp[i][1];
            res.push_back(nums[i]);
        }
        if(flag) {
            res.erase(res.begin());
        }
        return res;
    }
};