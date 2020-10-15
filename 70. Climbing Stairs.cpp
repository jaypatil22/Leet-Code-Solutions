class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
            return n;
        int p1= 2,p2=1,res=0;
        for(int i=2;i<n;i++) {
            res = p1+p2;
            p2 = p1;
            p1 = res;
        }
        return res;
    }
};
