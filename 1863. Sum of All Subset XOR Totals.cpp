class Solution {
public:
    void helper(int i,vector<int> &nums,int xr,int &res) {
        if(i>=nums.size()) return;
        xr = xr^nums[i];
        res += xr;
        for(int j=i+1;j<nums.size();j++) {
            helper(j,nums,xr,res);
        }
    }
    int subsetXORSum(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++) {
            helper(i,nums,0,res);
        }
        return res;
    }
};