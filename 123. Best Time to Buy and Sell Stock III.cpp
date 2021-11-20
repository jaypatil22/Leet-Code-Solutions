class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> leftToRight(n,0),rightToLeft(n,0);
        int minimum = prices[0];
        for(int i=1;i<prices.size();i++) {
            minimum = min(minimum, prices[i]);
            leftToRight[i] = max(leftToRight[i-1],prices[i]-minimum);
        }
        int maximum = prices[n-1];
        for(int i=n-2;i>=0;i--) {
            maximum = max(prices[i],maximum);
            rightToLeft[i] = max(rightToLeft[i+1],maximum-prices[i]);
        }
        int res = 0;
        for(int i=0;i<n;i++) {
            if(leftToRight[i] + rightToLeft[i] > res)  res = leftToRight[i] + rightToLeft[i];
        }
        return res;
    }
};