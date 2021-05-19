class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,maxf=0,n=s.size();
        vector<int> cnt(26);
        for(int i=0;i<n;i++) {
            maxf = max(maxf,++cnt[s[i]-'A']);
            if(i-l+1>maxf+k) {
                --cnt[s[l++]-'A'];
            }
        }
        return n-l;
    }
};