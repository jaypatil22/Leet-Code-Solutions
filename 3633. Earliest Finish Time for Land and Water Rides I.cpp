class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int res = INT_MAX;
        for(int i=0;i<landStartTime.size();i++) {
            for(int j = 0;j<waterStartTime.size();j++) {
                int lf_e = max(landStartTime[i]+landDuration[i],waterStartTime[j]);
                lf_e = lf_e + waterDuration[j];
                res = min(res, lf_e);
                int wf_e = max(waterStartTime[j]+waterDuration[j], landStartTime[i]);
                wf_e = wf_e + landDuration[i];
                res = min(res, wf_e);
            }
        }
        return res;
    }
};