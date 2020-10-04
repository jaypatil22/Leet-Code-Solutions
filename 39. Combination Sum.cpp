class Solution {
public:

    void backtrack(vector<vector<int> > &res,vector<int> &candidates, int target, vector<int> current,int index) {
        if(target < 0)
            return;
        if(target == 0) {
            res.push_back(current);
            return;
        }
        for(int i=index;i<candidates.size();i++) {
            current.push_back(candidates[i]);
            backtrack(res,candidates,target-candidates[i],current,i);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        backtrack(res,candidates,target,{},0);
        return res;

    }
};
