class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1 == "0")
            return num2;
        if(num2 == "0")
            return num1;
        string res = "";
        int i = num1.size()-1,j= num2.size()-1;
        int carry = 0;
        while(i>=0 && j>=0) {
            int temp = (num1[i]-'0')+(num2[j]-'0')+carry;
            res += to_string(temp%10);
            carry = temp/10;
            i--;j--;
        }
        while(i>=0) {
            int temp = (num1[i]-'0')+carry;
            res+= to_string(temp%10);
            carry = temp /10;
            i--;
        }
        while(j>=0) {
            int temp = (num2[j]-'0')+carry;
            res += to_string(temp%10);
            carry = temp /10;
            j--;
        }
        while(carry != 0) {
            res += to_string(carry%10);
            carry /= 10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
