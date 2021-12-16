class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> m;
        for(int i=0;i<nums.size();i++) {
            m.push_back(make_pair(nums[i],i));
        }
        sort(m.rbegin(),m.rend());
        vector<pair<int,int>> m1;
        for(auto a : m) {
            m1.push_back(a);
            k--;
            if(k ==0 ) break;
        }
        vector<int> res;
        sort(m1.begin(),m1.end(),[](const pair<int,int>&a,const pair<int,int>&b){return a.second < b.second;});
        for(auto a : m1) {
            res.push_back(a.first);
        }
        return res;
    }
};