class Solution {
public:
    int numTilings(int n) {
        const int mod = 1e9+7;
        if(n==1) return 1;
        if(n==2) return 2;
        long long fkm2 = 1, fkm1 = 2, pkm1 = 1;
        for(int i=3;i<=n;i++) {
            long long fk = fkm1 + fkm2 + 2 * pkm1;
            long long pk = pkm1 + fkm2;
            fkm2 = fkm1;
            fkm1 = fk%mod;
            pkm1 = pk%mod;
        }
        return fkm1;
    }
};