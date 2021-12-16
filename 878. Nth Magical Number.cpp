class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        const int mod = 1e9+7;
        int lcm = a * b / __gcd(a,b);
        int m = lcm/a + lcm/b -1;
        int q = n/m, r = n%m;
        
        long long ans = ((long long) lcm * (q)) % mod;
        cout << ans << endl;
        if(r==0) return ans;
        
        int heads[2] = {a,b};
        for(int i=0;i<r-1;i++) {
            if(heads[0] <= heads[1]) {
                heads[0] += a;
            } else {
                heads[1] += b;
            }
        }
        ans += min(heads[0],heads[1]);
        return ans%mod;
    }
};