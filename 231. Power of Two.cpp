class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        int cnt = 0;
        for(int i=0;i<31;i++) {
            if((n>>i) & 1) cnt++;
        }
        return cnt == 1;
    }
};