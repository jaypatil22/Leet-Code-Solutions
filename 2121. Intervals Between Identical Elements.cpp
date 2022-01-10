class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<arr.size();i++) {
            m[arr[i]].push_back(i);
        }
        vector<long long> pre(arr.size(),0),suf(pre),res(pre);
        for(auto &a : m) {
            auto v = a.second;
            for(int i=1;i<v.size();i++) {
                pre[v[i]] = pre[v[i-1]] + (long long)i*(v[i]-v[i-1]);
            }
            
            for(int i=v.size()-2;i>=0;i--) {
                suf[v[i]] = suf[v[i+1]] + (long long)(v.size()-1-i)*(v[i+1]-v[i]);
            }
        }
        for(int i=0;i<arr.size();i++) {
            res[i] = suf[i]+pre[i];
        }
        return res;
    }
};