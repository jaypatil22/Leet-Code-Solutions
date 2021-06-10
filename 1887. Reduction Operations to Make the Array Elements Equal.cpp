class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        vector<int> cnt(50001,0);
        for(int i=0;i<nums.size();i++) {
            cnt[nums[i]]++;
        }
        int curr=0,res=0;
        for(int i=50000;i>0;i--) {
            if(cnt[i]) {
                curr += cnt[i];
                res += curr;
            }
        }
        return res-curr;
    }
};