class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0,j,k;
        stack<int> s;
        int n=nums.size();
        for(int i=0;i<=n;i++) {
            while(!s.empty() && nums[s.top()] > (i==n ? -2e9 : nums[i])) {
                j = s.top();s.pop();
                k = s.empty() ? -1 : s.top();
                res -= nums[j] * (i-j) * (j-k);
            }
            s.push(i);
        }
        s = {};
        for(int i=0;i<=n;i++) {
            while(!s.empty() && nums[s.top()] < (i==n ? 2e9 : nums[i])) {
                j = s.top();s.pop();
                k = s.empty() ? -1 : s.top();
                res += nums[j] * (i-j) * (j-k);
            }
            s.push(i);
        }
        return res;
    }
};