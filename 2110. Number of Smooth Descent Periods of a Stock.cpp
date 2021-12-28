class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        vector<long long> v(prices.size(),1);
        for(int i=1;i<prices.size();i++) {
            if(prices[i-1]-1 == prices[i]) {
                v[i] = v[i-1]+1;
            }
        }
        long long res = 0;
        for(int a : v) res += a;
        return res;
    }
};