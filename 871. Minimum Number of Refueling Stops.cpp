class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        sort(stations.begin(),stations.end());
        vector<long long> dp(stations.size()+1,0);
        dp[0] = startFuel;
        long long curF=startFuel,curC=0;
        for(int i=0;i<stations.size();i++) {
            for(int t = i;t>=0;t--) {
                if(dp[t] >= stations[i][0]) {
                    dp[t+1] = max(dp[t+1],dp[t]+stations[i][1]);
                }
            }
        }
        for(int i=0;i<dp.size();i++) {
            if(dp[i]>=target) return i;
        }
        return -1;
        
    }
};