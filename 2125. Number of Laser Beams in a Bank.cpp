class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0,prev = 0;
        for(string &s : bank) {
            int cnt = 0;
            for(char &c : s) {
                if(c=='1') cnt++;
            }
            res += prev*cnt;
            if(cnt) prev = cnt;
        }
        return res;
    }
};