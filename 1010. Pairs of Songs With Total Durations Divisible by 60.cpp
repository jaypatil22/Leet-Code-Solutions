class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<vector<int>> rem(60);
        for(int i=0;i<time.size();i++) {
            rem[time[i]%60].push_back(i);
        }
        int res = 0;
        for(int i=1;i<30;i++) {
            res += rem[i].size()*rem[60-i].size();
        }
        res += rem[0].size()*(rem[0].size()-1)/2;
        res += rem[30].size()*(rem[30].size()-1)/2;
        return res;
    }
};