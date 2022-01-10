class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),[&](const auto &a,const auto &b){ return a[1] < b[1]; });
        unordered_map<int,int> m;
        for(auto &t: trips) {
            m[t[2]] += t[0];
        }
        int e = 0;
        for(auto &t : trips) {
            while(e<=t[1]) {
                if(m.find(e) != m.end()) capacity += m[e];
                e++;
            }
            if(t[0] > capacity) return false;
            capacity -= t[0];
        }
        return true;
    }
};