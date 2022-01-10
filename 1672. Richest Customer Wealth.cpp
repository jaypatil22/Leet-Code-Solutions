class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for(auto a : accounts) {
            int sum = 0;
            for(int b : a) {
                sum += b;
            }
            if(sum > res) res = sum;
        }
        return res;
    }
};