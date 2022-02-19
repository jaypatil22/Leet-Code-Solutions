class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto &a : nums) {
            m[a]++;
        }
        vector<int> res;
        for(int i=0;i<nums.size();i++) {
            if(m[nums[i]]==1) {
                if(m.find(nums[i]+1)==m.end() && m.find(nums[i]-1)==m.end()) res.push_back(nums[i]);
            }
        }
        return res;
    }
};