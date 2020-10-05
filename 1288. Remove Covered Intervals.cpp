class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int res = 0;
        vector<bool> covered(intervals.size());
        for(int i =0;i<intervals.size();i++) {
            for(int j = 0;j<intervals.size();j++) {
                if(i == j)
                    continue;
                if(intervals[i][1] <= intervals[j][1] && intervals[j][0] <= intervals[i][0] && ! covered[i] ) {
                    res++;
                    covered[i] = 1;
                    break;
                }
            }
        }
        return intervals.size()-res;
    }
};
