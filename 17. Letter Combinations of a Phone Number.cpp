class Solution {
public:

    const string SEQ[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(vector<string> &res,string digits,int i, string inter) {
        if(inter.size() == digits.size()) {
            res.push_back(inter);
            return;
        }
        backtrack(res,digits,i+1,inter+SEQ[(digits[i] - '0')][0]);
        backtrack(res,digits,i+1,inter+SEQ[(digits[i] - '0')][1]);
        backtrack(res,digits,i+1,inter+SEQ[(digits[i] - '0')][2]);
        if(digits[i] == '9' || digits[i] == '7')
            backtrack(res,digits,i+1,inter+SEQ[(digits[i] - '0')][3]);
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0)
            return res;
        backtrack(res,digits,0,"");
        return res;
    }
};
