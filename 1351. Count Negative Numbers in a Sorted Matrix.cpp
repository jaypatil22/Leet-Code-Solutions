class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans(0);

        for (auto a : grid) {
            ans += upper_bound(a.rbegin(),a.rend(),-1) - a.rbegin();
        }

        return ans;
    }
};
