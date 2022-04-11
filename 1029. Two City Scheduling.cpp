class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[](const auto &a, const auto &b){ return a[0]-a[1] < b[0]-b[1];});
        int n = costs.size(),res = 0;
        for(int i=0;i<n;i++) {
            if(i<n/2) {
                res += costs[i][0];
            } else {
                res += costs[i][1];
            }
        }
        return res;
    }
};