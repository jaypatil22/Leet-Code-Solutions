class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        string mul(num1.size()+num2.size(),'0');
        for(int i = num1.size()-1;i>=0;i--) {
            int carry = 0;
            for(int j = num2.size()-1;j>=0;j--) {
                int temp = (mul[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                mul[i+j+1] = temp%10 + '0';
                carry = temp/10;
            }
            mul[i] += carry;
        }
        auto start = mul.find_first_not_of("0");
        return mul.substr(start);
    }
};