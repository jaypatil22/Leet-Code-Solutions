class Solution {
public:
    bool checkZeroOnes(string s) {
        int ones=0,zeroes=0,i=0;
        while(i<s.size()) {
            if(s[i]=='0') {
                int cnt=1;
                while(i<s.size() && s[i]==s[i+1]) {
                    cnt++;i++;
                }
                if(cnt > zeroes) zeroes=cnt;
            } else {
                int cnt =1;
                while(i<s.size() && s[i]==s[i+1]) {
                    cnt++;i++;
                }
                if(cnt>ones) ones = cnt;
            }
            i++;
        }
        return ones > zeroes;
    }
};