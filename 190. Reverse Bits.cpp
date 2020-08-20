class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev=0,p=31;
        while(n!=0) {
            rev = rev + ((n&1)<<p);
            n = n>>1;
            p -= 1;
        }

        return rev;
    }
};
