class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > res;
        if(intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0],end=intervals[0][1];
        int pos = 1;
        while(pos < intervals.size()) {
            while(pos < intervals.size() && intervals[pos][0] <= end) {
                end = max(end,intervals[pos][1]);
                pos++;

            }
            //end = max(end,intervals[pos-1][1]);
            res.emplace_back(vector<int> {start,end});
            if(pos < intervals.size()) {
                start = intervals[pos][0];
                end = intervals[pos][1];
            }
        }
        return res;
    }
};
