class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        for(int i=0;i<32;i++) {
            if((c>>i) & 1) {
                
                if(((a>>i)&1) or ((b>>i)&1)) {
                    // cout<< i <<" case1\n" ;
                    // res++;
                } else {
                    res++;
                }
            } else {
                if((a>>i)&1) {
                    res++;
                }
                if((b>>i)&1) {
                    res++;
                }
            }
        }
        return res;
    }
};