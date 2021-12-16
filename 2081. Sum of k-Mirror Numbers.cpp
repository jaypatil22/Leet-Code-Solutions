    class Solution {
public:
    vector<long long> mirror1{0},mirror2{0};
    long long isMirror(long long num, int base) {
    long long mul = 1;
    while (mul * base <= num)
        mul *= base;
    for (; num; mul /= base * base) {
        if (num / mul != num % base)
            return false;
        num = (num - (num / mul) * mul - num % base) / base;
    }
    return true;
}
    long long generate(int dig,int n,int k, long long first_mul) {
        long long res = 0;
        vector<long long> mirror;
        for(int i=0;i<10 && n>0;i++) {
            for(int j=0;j<mirror1.size() && n>0;j++) {
                mirror.push_back(i*first_mul+mirror1[j]*10+i);
                if(i != 0 && isMirror(mirror.back(),k)) {
                    res += mirror.back();
                    n--;
                }
            }
        }
        swap(mirror1,mirror2);
        swap(mirror2,mirror);
        return res + (n==0 ? 0 : generate(dig+1,n,k,first_mul*10));
    }
    long long kMirror(int k, int n) {
        long long res = 0;
        for(int i=1;i<10 && n>0;i++) {
            mirror2.push_back(i);
            if(isMirror(i,k)) {
                res += i;
                n--;
            }
        }  
        return res + generate(2,n,k,10);
    }
};