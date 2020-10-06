class Solution {
public:
    bool isHappy(int n) {

        vector<int> sq = {0, 1, 4, 9, 16, 25,36,49,64,81};
        while(n>10) {
            int temp = 0,t1 = n;
            while(n/10) {
                temp += sq[n%10];
                n /= 10;
            }
            temp += sq[n];
            n = temp;
            //cout << temp << "\n";
        }
        if(n == 1 || n == 7 || n == 10)
            return true;
        return false;

    }
};
