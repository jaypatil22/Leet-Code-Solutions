class Solution {
public:
    int secondHighest(string s) {
        set<int> se;
        for(int i=0;i<s.size();i++) {
            if(isdigit(s[i])) {
                se.insert(s[i]-'0');
            }
        }
        vector<int> res(se.begin(),se.end());
        if(res.size()<=1)
            return -1;
        sort(res.begin(),res.end());
        return res[res.size()-2];
    }
};