class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> count;
        for(string &word : words) {
            count[word]++;
        }
        int n = s.size(), num = words.size(), len = words[0].size();
        vector<int> res;
        for(int i=0;i<n-num*len+1;i++) {
            unordered_map<string,int> seen;
            int j = 0;
            for(;j<num;j++) {
                string sub = s.substr(i+j*len,len);
                if(count.find(sub) != count.end()) {
                    seen[sub]++;
                    if(seen[sub] > count[sub]) break;
                } else {
                    break;
                }
            }
            if(j==num) res.push_back(i);
        }
        return res;
    }
};