class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int obsp = -prices[0], ossp = 0, ocsp = 0;
        for(int i=1;i<n;i++) {
            int nbsp, nssp, ncsp;
            nbsp = max(obsp, ocsp - prices[i]);
            nssp = max(ossp, obsp + prices[i]);
            ncsp = max(ocsp, ossp);
            obsp = nbsp,ossp = nssp, ocsp  = ncsp;
        }
        return ossp;
    }
};