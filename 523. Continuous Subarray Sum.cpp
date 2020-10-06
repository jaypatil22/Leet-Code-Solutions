class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> modk;
        int sum = 0,pre = 0;
        for(int i = 0;i<nums.size();i++) {
            sum += nums[i];
            int mod = k==0 ? sum : sum%k;
            if(modk.count(mod)) return true;
            modk.insert(pre);
            pre = mod;
        }
        return false;
    }
};
