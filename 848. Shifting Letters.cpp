class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        vector<long long> suf(shifts.begin(),shifts.end());
        for(int i=s.size()-2;i>=0;i--) {
            suf[i] += suf[i+1];
        }
        for(int i =0;i<s.size();i++) {
            suf[i] %= 26;
        }
        for(int i=0;i<s.size();i++) {
            int a = s[i] + suf[i];
            // cout << a << endl;
            if(a > 'z') {
                s[i] = 'a' + (a-'z')-1;
            } else {
                s[i] = a;
            }
        }
        return s;
    }
};