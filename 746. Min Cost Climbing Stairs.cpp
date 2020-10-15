class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 2)
            return min(cost[0],cost[1]);
        int prev1=cost[1],prev2=cost[0],res=0;
        for(int i =2;i<cost.size();i++) {
            res = min(prev1,prev2)+cost[i];
            prev2 = prev1;
            prev1 = res;
            //cout << prev1 << " " << prev2 <<  " ";
        }
        return min(res,prev2);
    }
};
