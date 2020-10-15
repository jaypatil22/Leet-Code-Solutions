class Solution {
public:
    int fib(int N) {
        if(N==0)
            return 0;
        if(N==1)
            return 1;
        int res = 0,prev1=1,prev2=0;
        for(int i=2;i<=N;i++) {
            res = prev1+prev2;
            prev2=prev1;
            prev1=res;
        }
        return res;
    }
};
