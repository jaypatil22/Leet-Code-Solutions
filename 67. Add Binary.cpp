class Solution {
public:
    string addBinary(string a, string b) {
        string sum(max(a.size(),b.size())+1,'0');
        int carry = 0,i;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for( i = 0;i<min(a.size(),b.size());i++) {
            int temp = (a[i] -'0')+(b[i]-'0')+carry;
            if(temp == 0) {
                sum[i] = '0';
                carry = 0;
            } else if(temp == 1) {
                sum[i] = '1';
                carry = 0;
            } else if(temp == 2) {
                sum[i] = '0';
                carry = 1;
            } else {
                sum[i] = '1';
                carry = 1;
            }
        }
        while(i < a.size()) {
            int temp= (a[i]-'0') + carry;
            if(temp == 0) {
                sum[i] = '0';
                carry = 0;
            } else if(temp == 1) {
                sum[i] = '1';
                carry = 0;
            } else if(temp == 2) {
                sum[i] = '0';
                carry = 1;
            }
            i++;
        }
        while(i < b.size()) {
            int temp= (b[i]-'0') + carry;
            if(temp == 0) {
                sum[i] = '0';
                carry = 0;
            } else if(temp == 1) {
                sum[i] = '1';
                carry = 0;
            } else if(temp == 2) {
                sum[i] = '0';
                carry = 1;
            }
            i++;
        }
        if(carry)
            sum[i]='1';
        reverse(sum.begin(),sum.end());
        auto start = sum.find_first_not_of("0");
        if(string::npos != start)
            return sum.substr(start);
        return "0";
    }
};
