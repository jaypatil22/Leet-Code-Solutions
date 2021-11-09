class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int steps = 0;
        while(left != right) {
            left = left >> 1;
            right = right >> 1;
            steps++;
        }
        return left << steps;
    }
};