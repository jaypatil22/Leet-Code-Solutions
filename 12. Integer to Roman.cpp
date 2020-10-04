class Solution {
public:
    string intToRoman(int num) {
        string res="";
        int roman[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string rc[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int i = 12;
        while(num > 0) {
            if(num/roman[i]) {
                num -= roman[i];
                res += rc[i];
            } else {
                i--;
            }
        }

        return res;
    }
};
