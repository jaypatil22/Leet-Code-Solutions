class Solution {
public:
    int bitwiseComplement(int N) {
         int a = 1;
        while(N > a) a = a*2+1;
        return N ^a;
    }
};
