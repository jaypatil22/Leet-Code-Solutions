class Solution {
public:

    void backtrack(vector<vector<int> > &res,int begin, vector<int> &nums) {
        if(begin >= nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i = begin;i<nums.size();i++) {
            swap(nums[i],nums[begin]);
            backtrack(res,begin+1,nums);
            swap(nums[i],nums[begin]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res,0,nums);
        return res;
    }
};
