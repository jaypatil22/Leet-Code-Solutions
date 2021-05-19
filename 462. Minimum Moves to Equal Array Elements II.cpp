class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int avg = nums[n/2];
        long long res=0;
        int l = 0,r=n-1;
        while(l<r) {
            res += nums[r]-nums[l];
            l++;r--;
        }
        return res;
    }
};