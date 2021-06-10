class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        int i=nums.size()-1;
        vector<int> dp(nums.size(),-1);
        while(i>=0) {
            if(i+k+1 < nums.size()) {
                if(dq.front()==dp[i+k+1]) {
                    dq.pop_front();
                }
            }
            if((i+1)<nums.size()) {
                while((!dq.empty()) && (dq.back()<dp[i+1])) dq.pop_back();
                dq.push_back(dp[i+1]);
            }
            dp[i] = nums[i];
            if(!dq.empty()) dp[i] += dq.front();
            i--;
        }
        return dp[0];
    }
};
auto speed = [] () {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
} ();