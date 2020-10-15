class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int> > alpha(26);
        int res=0;
        for(int i=0;i<S.size();i++) alpha[S[i]-'a'].emplace_back(i);

        for(auto const word : words) {
            bool found = true;
            int x = -1;
            for(auto c : word) {
                auto it = upper_bound(alpha[c-'a'].begin(),alpha[c-'a'].end(),x);
                if(it == alpha[c-'a'].end()) {found=false; break;}
                else
                    x = *it;
            }
            if(found) res++;
        }
        return res;
    }
};
