class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> counter;
        int n = nums.size();
        for(auto a : nums) {
            counter[a]++;
            if(counter[a] > n/2){
                return a;
            }
        }
        return -1;
    }
};
