class Solution {
public:
    bool isPerfectSquare(int num) {
        long long sum = 0,odd = 1;
        while(sum < num) {
            sum += odd;
            odd += 2;
            if(sum == num) return true;
        }
        return false;
    }
};
