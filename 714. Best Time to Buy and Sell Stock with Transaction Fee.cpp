class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int bs = -prices[0] - fee, ss = 0;
        for(int i=1;i<prices.size();i++) {
            int nss, nbs;
            nbs = max(bs,ss - prices[i] - fee);
            nss = max(ss, bs + prices[i]);
            ss = nss, bs = nbs;
        }
        return ss;
    }
};