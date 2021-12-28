class Solution {
public:
    string abbreviateProduct(int left, int right) {
        long long suf = 1, c = 0, max_suf = 10000000000;
        double pref = 1.0, max_pref = 100000;
        bool large = false;
        for(int i=left;i<=right;i++) {
            suf *= i;
            pref *= i;
            while(pref >= max_pref) {
                pref /= 10;
            }
            while(suf%10 == 0) {
                suf /= 10;
                c++;
            }
            large |= (suf >= max_suf);
            suf %= max_suf;
        }
        string s = to_string(suf);
        return (large ? to_string((int)pref)+"..."+s.substr(s.size()-5) : s)+"e"+to_string(c);
    }
};