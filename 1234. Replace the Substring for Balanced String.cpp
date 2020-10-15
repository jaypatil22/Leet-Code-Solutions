class Solution {
public:
    int balancedString(string s) {
        vector<int> m(128);
        int res=s.size(),j=0;
        int n = s.size()/4;
        for(char a : s) {
            m[a]++;
        }
        //cout << m['Q'] << " " << m['W'] << " " << m['E'] << " " << m['R'] ;
        for(int i = 0;i<s.size();i++) {
            --m[s[i]];
            while(j<s.size() && m['Q'] <= n && m['W'] <= n && m['E'] <= n && m['R'] <= n) {
                res = min(res,i-j+1);
                ++m[s[j++]];
            }
        }

        return res;

    }
};
