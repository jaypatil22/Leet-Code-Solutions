class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum =0,res=0;
        map<int,int> m;
        m[0]++;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            if(m[sum-k])
                res += m[sum-k];
            m[sum]++;
        }
        return res;
    }
};
