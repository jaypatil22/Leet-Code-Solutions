class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        unordered_set<int> a;
        for(int i : nums) {
            m[i]++;
            a.insert(i);
        }
        vector<int> idx;
        for(int i : a) idx.push_back(i);
        sort(idx.begin(),idx.end(),[&](const auto a,const auto b){ return m[a] > m[b];});
        vector<int> res;
        for(int i=0;i<k;i++) {
            res.push_back(idx[i]);
        }
        return res;
    }
};