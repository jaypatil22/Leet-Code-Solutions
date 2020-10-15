class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        vector<int> cnt(26,INT_MAX);

        for(auto a : A) {
            vector<int> cnt1(26,0);
            for(auto c : a) ++cnt1[c-'a'];
            for(int i=0;i<26;i++) cnt[i] = min(cnt[i],cnt1[i]);
        }

        for(int i=0;i<26;i++) {
            for(int j=0;j<cnt[i];j++) res.emplace_back(string(1,i+'a'));
        }

        return res;
    }
};
