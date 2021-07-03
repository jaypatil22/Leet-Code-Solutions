class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> idx(101);
        for(int i=0;i<nums.size();i++) {
            idx[nums[i]].push_back(i);
        }
        vector<int> res;
        for(int i=0;i<queries.size();i++) {
            int prev = 0,delta = INT_MAX;
            for(int j=1;j<=100;j++) {
                auto it = lower_bound(idx[j].begin(),idx[j].end(),queries[i][0]);
                if(it!=idx[j].end() && *it<=queries[i][1]) {
                    delta = min(delta,((prev==0)?INT_MAX:j-prev));
                    prev = j;
                }
            }
            res.push_back((delta==INT_MAX)?-1:delta);
        }
        return res;
    }
};