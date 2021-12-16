class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        const int mx = 2e5+2;
        startPos++;
        vector<int> f(mx,0);
        for(auto a : fruits) f[a[0]+1] = a[1];
        for(int i=1;i<f.size();i++) {
            f[i] += f[i-1];
        }
        int res = 0,r,l;
        for(r=startPos;r<mx && r < startPos+k;r++) {
            l = min(startPos,startPos - (k-2*(r-startPos)));
            l = max(1,l);
            res = max(res,f[r]-f[l-1]);
        }
        
        for(l = startPos;l>0 && l >= startPos-k;l--) {
            r = max(startPos,startPos + (k-2*(startPos-l)));
            r = min(r,mx-1);
            res = max(res,f[r]-f[l-1]);
        }
        return res;
    }
};