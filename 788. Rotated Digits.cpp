class Solution {
public:
    bool check(int i) {
        int rotated=0;
        string dup = to_string(i);
        for(int j=0;j<dup.size();j++) {
            int unit = dup[j]-'0';
            rotated *= 10;
            if(unit ==3 || unit == 4 || unit == 7) return false;
            if(unit == 0 || unit == 1 || unit == 8) {
                rotated += unit;
            } else if(unit == 2) {
                rotated += 5;
            } else if(unit == 5) {
                rotated += 2;
            } else if(unit == 6) {
                rotated += 9;
            } else if(unit == 9) {
                rotated += 6;
            }
        }
        return rotated != i;
    }
    int rotatedDigits(int n) {
        int res = 0;
        for(int i=1;i<=n;i++) {
            res += check(i);
        }
        return res;
    }
};