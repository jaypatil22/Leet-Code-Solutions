class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> freq;
        int res = INT_MAX;
        for(int i=0;i<nums.size();i++) {
            freq[nums[i]].push_back(i);
        }
        for(auto [k, v] : freq) {
            if(v.size()<3) {
                continue;
            }
            for(int j=0;j+2<v.size();j++) {
                res = min(res, (abs(v[j]-v[j+1])+abs(v[j+1]-v[j+2])+abs(v[j]-v[j+2])));
            }
            cout << res << endl;
        }
        if(res==INT_MAX) return -1;
        return res;
    }
};