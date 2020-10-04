class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.size() < 1)
            return res;
        if(strs.size() == 1)
            return strs[0];
        for(int i =0;i<strs[0].size();i++) {
            for(int j =0;j<strs.size();j++) {
                if(strs[0][i] != strs[j][i]) {
                    return res;
                }
            }
            res += strs[0][i];
        }

        return res;
    }
};
