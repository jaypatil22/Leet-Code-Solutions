class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int res = INT_MAX;
        unordered_map<int, set<int>> map;
        for(int i =0;i<nums.size();i++) {
            map[nums[i]].insert(i);
        }
        for(int i=0;i<nums.size();i++) {
            int reverse = 0, copy=nums[i];
            while(copy) {
                reverse *= 10;
                reverse += copy%10;
                copy /= 10;
            }
            if(map[reverse].size()) {
                auto it = map[reverse].upper_bound(i);
                if(it == map[reverse].end()) continue;
                res = min(res, abs(*it-i));
            }
        }
        if(res == INT_MAX) return -1;
        return res;
    }
};