class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> res(nums.size(),-1);
        long long sum = 0;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            if(i>=2*k) {
                res[i-k] = sum/(2*k+1);
                sum -= nums[i-2*k];
            }
        }
        return res;
    }
};

auto speedup = []() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();