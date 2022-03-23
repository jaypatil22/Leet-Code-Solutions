class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n,'a');
        k -= n;
        int i = n-1;
        while(k) {
            if(k > 25) {
                k -= 25;
                res[i] += 25;
            } else {
                res[i] += k;
                break;
            }
            i--;
        }
        return res;
    }
};