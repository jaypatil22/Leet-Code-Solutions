class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int pos1 = 0,pos2 = 0;
        vector<vector<int> > res;
        if(intervals.size() == 0){
            res.push_back(newInterval);
            return res;
        }
        while(pos1 < intervals.size() && intervals[pos1][1] < newInterval[0]) {
            res.emplace_back(intervals[pos1]);
            pos1++;
        }
        int start;
        if(pos1==intervals.size())
            start = newInterval[0];
        else
            start = min(intervals[pos1][0],newInterval[0]);
        while(pos1 < intervals.size() && intervals[pos1][0] <= newInterval[1]) {
            pos1++;
        }
        int end;
        if(pos1-1 <0)
            end= newInterval[1];
        else
            end = max(intervals[pos1-1][1],newInterval[1]);
        res.emplace_back(vector<int> {start,end});

        while(pos1 < intervals.size()) {
            res.emplace_back(intervals[pos1]);
            pos1++;
        }
        //cout << pos1 << " " << pos2 << " ";
        return res;
    }
};
