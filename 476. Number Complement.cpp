class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        int i = 31;
        while(!((1<<i) & num)) {
            i--;
        }
        for(;i>=0;i--) {
            num ^= 1<<i;
        }
        return num;
    }
};