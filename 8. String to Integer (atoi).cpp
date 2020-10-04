#include <climits>
class Solution {
public:
    int myAtoi(string str) {
        if(str.size() < 1)
         return 0;
        int i=0;
        long long int res =0;
        while(strncmp(&str[i]," ",1)==0) {
            i++;
        }
        if(!isdigit(str[i]) && strncmp(&str[i],"+",1)==0 && strncmp(&str[i],"-",1)==0) {
            return 0;
        }
        bool minus =0;
        if(str[i] == '-') {
            minus = 1;
            i++;
        }else if(str[i] == '+')
            i++;
        while(isdigit(str[i])) {
            if(res > INT_MAX)
                break;
            res = res*10 + (str[i]-48);
            i++;
        }

        if(minus)
            res *= -1;
        if(res > INT_MAX)
            res = INT_MAX;
        if(res < INT_MIN)
            res = INT_MIN;
        return res;
    }
};a
