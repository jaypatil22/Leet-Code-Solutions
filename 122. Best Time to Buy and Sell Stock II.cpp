class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i =1;i<prices.size();i++) {
            profit += max(0,prices[i]-prices[i-1]);
        }
        return profit;

    }
};
