class Solution {
public:

    void backtrack(vector<vector<int> > &res, int n, int k, int index,vector<int> current) {
        if(current.size() == k) {
            res.push_back(current);
            return;
        }

        for(int i = index;i<=n;i++) {
            current.push_back(i);
            backtrack(res,n,k,i+1,current);
            current.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        backtrack(res, n, k, 1,{});
        return res;
    }
};
