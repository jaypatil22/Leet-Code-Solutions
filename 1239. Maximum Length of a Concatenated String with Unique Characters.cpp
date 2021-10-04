class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<string> res;
        res.push_back("");
        int r = 0;
        for(auto word : arr) {
            int len = res.size();
            for(int j=0;j<len;j++) {
                string nw = res[j] + word;
                unordered_set<char> c(nw.begin(),nw.end());
                if(nw.size() != c.size()) continue;
                res.push_back(nw);
                if(nw.size() > r) r = nw.size();
            }
        }
        return r;
    }
};