class Solution {
public:
    int countPrimes(int n) {
        if(n<=1)
            return 0;
        int res =0;
        vector<bool> sieve(n+1,true);
        for(int p=2;p*p<=n;p++) {
            if(sieve[p]) {
                for(int i=p*p;i<=n;i+=p) {
                    sieve[i] = false;
                }
            }
        }
        for(int i=2;i<n;i++) {
            if(sieve[i] == true)
                res++;
        }
        return res;
    }
};
