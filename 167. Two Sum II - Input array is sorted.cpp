class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int front=0,end=numbers.size()-1;
        while(front < end) {
            if(numbers[front]+numbers[end] == target) {
                res.emplace_back(front+1);
                res.emplace_back(end+1);
                return res;
            }
            if(numbers[front]+numbers[end] < target) {
                front++;
            } else {
                end--;
            }
        }
        return res;
    }
};