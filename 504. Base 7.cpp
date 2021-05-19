class Solution {
public:
    string convertToBase7(int num) {
        if(num==0) return "0";
        string res="";
        int sign = num<0?-1:1;
        num=abs(num);
        while(num) {
            int a = num%7;
            res.push_back((a+'0'));
            num/=7;
        }
        reverse(res.begin(),res.end());
        if(sign==-1) {
            res.insert(0,1,'-');
        }
        return res;
    }
};