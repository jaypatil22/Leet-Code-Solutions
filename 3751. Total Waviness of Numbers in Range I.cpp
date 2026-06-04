class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int res = 0;
        for(int i = num1;i<=num2;i++) {
            string num = to_string(i);
            if(num.size()<3) continue;
            else {
                for(int j=1;j<num.size()-1;j++) {
                    if(num[j-1] < num[j] && num[j+1] < num[j]) res++;
                    else if(num[j-1] > num[j] && num[j+1] > num[j]) res++;
                }
            }
        }
        return res;
    }
};