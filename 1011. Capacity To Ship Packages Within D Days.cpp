class Solution {
public:
    bool isFeasible(vector<int>&weights, int days,int ma) {
        int d = 1,sum = 0;
        for(int &i : weights) {
            if(sum + i > ma) {
                d++;
                if(d > days) return false;
                sum = i;
            } else {
                sum += i;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ma = 0,mi = INT_MIN;
        for(int &i : weights) {
            if(i > mi) mi = i;
            ma += i;
        }
        int res = 0;
        while(ma >= mi) {
            int mid = (ma+mi)/2;
            if(isFeasible(weights,days,mid)) {
                // res = mid;
                ma = mid -1;
            } else {
                mi = mid+1;
            }
        }
        return mi;
    }
};