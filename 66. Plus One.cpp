class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0,pos = digits.size()-1;
        while(pos>=0 && digits[pos] == 9) {
            digits[pos] = 0;
            pos--;
        }
        if(pos < 0 )
            digits.insert(digits.begin(),1);
        else {
        digits[pos] += 1;
        }
        return digits;

    }
};
