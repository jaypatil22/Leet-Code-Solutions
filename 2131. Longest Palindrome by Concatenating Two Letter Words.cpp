class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> m;
        for(string s : words) {
            m[s]++;
        }
        int cnt = 0,flag = 0;
        for(auto p : m) {
            string x = p.first;
            string y = x;
            reverse(y.begin(),y.end());
            if(y != x) {
                int c = min(m[x],m[y]);
                m[x]-=c;m[y]-=c;
                cnt += c;
            } else {
                int c = m[x]/2;
                cnt += c;
                if(m[x]%2) {
                    flag = 1;
                }
                m[x] = 0;
            }
        }
        cnt *= 4;
        if(flag) cnt += 2;
        return cnt;
    }
};