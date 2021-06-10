class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int cur = 0,res=0,l=0;
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++) {
            cur+=nums[i];
            if(s.find(nums[i])!=s.end()) {
                while(nums[l] != nums[i]) {
                    s.erase(s.find(nums[l]));
                    cur -= nums[l];
                    l++;
                }
                cur -= nums[l];
                s.erase(nums[l]);
                l++;
            }
            s.insert(nums[i]);
            if(res<cur) res = cur;
        }
        return res;
    }
};