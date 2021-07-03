class Solution {
public:
    string largestOddNumber(string num) {
        int res = -1;
        for(int i=0;i<num.size();i++) {
            if((num[i]-'0')&1) {
                res = i;
            }
        }
        if(res==-1) return "";
        return num.substr(0,res+1);
    }
};