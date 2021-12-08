class Solution {
public:
    void helper(vector<vector<int>> &res,vector<int> &nums, vector<int> &cur, int i) {
        res.push_back(cur);
        for(int j = i;j<nums.size();j++) {
            if(j!=i && nums[j]==nums[j-1]) continue;
            cur.push_back(nums[j]);
            helper(res,nums,cur,j+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(),nums.end());
        // res.push_back({});
        helper(res,nums,cur, 0);
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();) {
            int count = 0;
            while(i+count < nums.size() && nums[i]==nums[i+count]) count++;
            int prevCount = res.size();
            for(int j = 0;j<prevCount;j++) {
                vector<int> sub = res[j];
                for(int k = 0;k<count;k++) {
                    sub.push_back(nums[i]);
                    res.push_back(sub);
                }
            }
            i += count;
        }
        return res;
    }
};