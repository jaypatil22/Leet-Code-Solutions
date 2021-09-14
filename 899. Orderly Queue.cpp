class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1) {
            string res = s;
            for(int i=1;i<s.size();i++) {
                string cur = s.substr(i) + s.substr(0,i);
                if(cur < res) res = cur;
            }
            return res;
        } else {
            sort(s.begin(),s.end());
            return s;
        }
    }
};