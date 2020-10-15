class Solution {
public:
    int bulbSwitch(int n) {
        vector<bool> bulbs(n,true);
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        int i = 1,res=0;
        while((long long)i*i <= n) {
            res++;
            i++;
        }
        return res;
    }
};
