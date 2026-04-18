class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        map<int, vector<int>> nums_map;
        vector<int> res;
        int n = nums.size();
        for(int i =0;i<nums.size();i++) {
            nums_map[nums[i]].push_back(i);
        }
        for(int i : queries) {
            if(nums_map[nums[i]].size()<2) {
                res.push_back(-1);
                continue;
            }
            int r = INT_MAX;
            int left = 0, right = nums_map[nums[i]].size()-1, ind;
            while(left <= right) {
                int mid = (left+right)/2;
                if(nums_map[nums[i]][mid] == i) {
                    ind = mid;
                    break;
                }
                if(nums_map[nums[i]][mid]<i) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
            int r_i, l_i;
            if(ind==0) {
                l_i = nums_map[nums[i]][nums_map[nums[i]].size()-1];
            } else {
                l_i = nums_map[nums[i]][ind-1];
            }
            if(ind == nums_map[nums[i]].size()-1) {
                r_i = nums_map[nums[i]][0];
            } else {
                r_i = nums_map[nums[i]][ind+1];
            }
            r = min(r, abs(i-l_i));
            r = min(r, n-abs(i-l_i));
            r = min(r, abs(i-r_i));
            r = min(r, n-abs(i-r_i));
            res.push_back(r);
        }
        return res;
    }
};