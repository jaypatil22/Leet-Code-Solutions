class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int res = 1;
        sort(nums.begin(),nums.end());
        for(int a:nums) {
            if(res == a)
                res++;
        }
        return res;

    }
};
