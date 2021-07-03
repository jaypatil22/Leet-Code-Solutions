class Solution {
public:
    void sort_count(vector<vector<int>>::iterator l,vector<vector<int>>::iterator r,vector<int> &res) {
        if(r-l<=1) return;
        auto mid = l + (r-l)/2;
        sort_count(l,mid,res);
        sort_count(mid,r,res);
        for(auto i=l,j=mid;i<mid;i++) {
            while(j<r && (*i)[0] > (*j)[0]) j++;
            res[(*i)[1]] += j-mid;
        }
        inplace_merge(l,mid,r);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<vector<int>> p;
        for(int i=0;i<nums.size();i++) {
            p.push_back({nums[i],i});
        }
        vector<int> res(nums.size(),0);
        sort_count(p.begin(),p.end(),res);
        return res;
    }
};