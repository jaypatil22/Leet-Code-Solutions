class Solution {
public:
    int minSwaps(string s) {
        int zeroes=0,ones=0;
        vector<int> zero_pos,one_pos;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='0') zeroes++,zero_pos.push_back(i);
            else ones++,one_pos.push_back(i);
        }
        if(abs(zeroes-ones)>1) return -1;
        int res=0;
        if(zeroes<ones) {
            int cnt=0;
            for(int i=0;i<s.size();i+=2) {
                if(s[i]!='1') cnt++;
            }
            return cnt;
        } else if(ones<zeroes) {
            int cnt=0;
            for(int i=0;i<s.size();i+=2) {
                if(s[i]!='0') cnt++;
            }
            return cnt;
        } else {
            int cnt=0;
            for(int i=0;i<s.size();i+=2) {
                if(s[i]!='1') cnt++;
            }
            int cnt2=0;
            // int cnt=0;
            for(int i=0;i<s.size();i+=2) {
                if(s[i]!='0') cnt2++;
            }
            return min(cnt,cnt2);
        }
        return res;
    }
};