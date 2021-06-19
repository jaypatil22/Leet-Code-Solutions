class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](const vector<int> &l,const vector<int> &r){return l[1]>r[1];});
        long long i=0, res = 0;
        while(truckSize && i<boxTypes.size()) {
            int take = min(truckSize,boxTypes[i][0]);
            res += take*boxTypes[i][1];
            truckSize -= take;
            i++;
        }
        
        return res;
    }
};