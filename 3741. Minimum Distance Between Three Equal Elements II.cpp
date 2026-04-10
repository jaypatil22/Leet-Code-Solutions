class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, int> occur;
        int n = nums.size();
        vector<int> next(n,-1);
        for(int i=n-1;i>=0;i--) {
            if(occur.count(nums[i])) {
                next[i] = occur[nums[i]];
            }
            occur[nums[i]] = i;
        }
        int res = INT_MAX;
        for(int i=0;i<n;i++) {
            int second = next[i];
            if(second != -1) {
                int third = next[second];
                if(third != -1) {
                    res = min(res, third-i);
                }
            }
        }
        if(res==INT_MAX) return -1;
        return res*2;
    }
};