class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res = 0;
        for(string &s :sentences) {
            int i=0;
            int cnt = 0;
            while(i<s.size()) {
                while(i<s.size() && s[i]==' ') i++;
                if(i<s.size()) {
                    cnt++;
                    while(i<s.size() && isalpha(s[i])) i++;
                }
            }
            if(cnt > res) res = cnt;
        }
        return res;
    }
};