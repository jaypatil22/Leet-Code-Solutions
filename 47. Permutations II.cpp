class Solution {
public:

    void backtrack(vector<vector<int> > &res,vector<int> nums,int l, int r) {
        if(l == r-1) {
            res.push_back(nums);
            return;
        }
        for(int i = l;i<r;i++) {
            if(i != l && nums[i] == nums[l]) continue;
            swap(nums[i],nums[l]);
            backtrack(res,nums,l+1,r);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(),nums.end());
        backtrack(res,nums,0,nums.size());
        return res;
    }

};
