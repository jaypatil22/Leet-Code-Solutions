class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(),res=0,mask=0;
        unordered_map<int,int> maxl;
        for(int i=0;i<n;i++) {
            mask = 0;
            for(auto c : words[i]) {
                mask |= (1<<(c-'a'));
            }
            for(auto a : maxl) {
                if((a.first&mask)==0) {
                    res = max(res,a.second*(int)words[i].size());
                }
            }
            maxl[mask] = max(maxl[mask],(int)words[i].size());
        }
        return res;
    }
};