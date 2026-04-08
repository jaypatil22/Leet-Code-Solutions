class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long mod = 1000000000 + 7;
        for(int i=0;i<queries.size();i++) {
            int l=queries[i][0],r=queries[i][1],k=queries[i][2],v=queries[i][3];
            for(;l<=r;l+=k) {
                nums[l] = ((long long)nums[l]*v)%mod;
                
            }
        }
        int res = 0;
        for(int n : nums) {
            res = res ^ n;
        }
        return res;
    }
};