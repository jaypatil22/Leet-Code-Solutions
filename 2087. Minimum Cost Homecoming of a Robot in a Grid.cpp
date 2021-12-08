class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        vector<int> x = {startPos[0],homePos[0]};
        vector<int> y = {startPos[1], homePos[1]};
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        int res=0;
        for(int i=x[0];i<=x[1];i++) {
            if(i==startPos[0]) continue;
            res += rowCosts[i];
        }
        for(int i=y[0];i<=y[1];i++) {
            if(i==startPos[1]) continue;
            res += colCosts[i];
        }
        return res;
    }
};