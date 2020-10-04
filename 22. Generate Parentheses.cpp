class Solution {
public:

    void backtrack(vector<string> &res, int left, int right, string s) {

        if(left ==0 && right == 0) {
            res.push_back(s);
            return;
        }

        if(left > 0) {
            backtrack(res,left-1,right,s+"(");
        }

        if(right > left) {
            backtrack(res, left,right-1,s+")");
        }


    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res,n,n,"");
        return res;
    }
};
