class Solution {
public:
    int n;
    vector<int> visited;
    int arrayNesting(vector<int>& nums) {
        int res = INT_MIN;
        n = nums.size();
        visited = vector<int>(n,0);
        for(int i=0;i<n;i++) {
            if(visited[i] == 0) {
                res = max(res,helper(nums,i));
            }
        }
        return res;
    }
    int helper(vector<int> &nums,int i) {
        if(visited[i]==1) return 0;
        visited[i] = 1;
        return 1 + helper(nums,nums[i]);
    }
};