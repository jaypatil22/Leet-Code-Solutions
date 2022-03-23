class Solution {
    int mod = 1e9 + 7;
    vector<vector<int>> memo;
public:
    int helper(int unpicked,int undelivered) {
        if(unpicked==0 && undelivered==0) {
            return 1;
        }
        if(unpicked < 0 || undelivered < 0 || undelivered < unpicked) return 0;
        
        if(memo[unpicked][undelivered]) return memo[unpicked][undelivered];
        
        long long res = 0;
        res += (long long)unpicked* helper(unpicked-1,undelivered);
        res %= mod;
        res += (long long)(undelivered-unpicked) * helper(unpicked,undelivered-1);
        res %= mod;
        return memo[unpicked][undelivered] = res;
    }
    int countOrders(int n) {
        memo = vector<vector<int>> (n+1,vector<int>(n+1,0));
        return helper(n,n);
    }
};