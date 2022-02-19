class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int start = 0;
        while(start<s.size()) {
            string sub = "";
            int k1 = k;
            while(start<s.size() && k1--) {
                sub.push_back(s[start++]);
            }
            res.push_back(sub);
        }
        while(res.back().size()<k) {
            res.back().push_back(fill);
        }
        return res;
    }
};