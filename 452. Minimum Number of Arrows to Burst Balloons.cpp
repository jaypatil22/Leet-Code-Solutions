class Solution {
public:

    static bool second(const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0)
            return 0;
        sort(points.begin(),points.end(), second);

        int i=0,end = points[0][1],res=0;
        while(i<points.size()) {
            res++;
            while(i<points.size() && end >= points[i][0]) i++;
            if(i < points.size())
            end = points[i][1];
        }

        return res;
    }
};
