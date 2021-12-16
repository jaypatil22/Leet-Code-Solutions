class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int mi = 0, ma = 0;
        for(int i=1;i<n;i++) {
            if(nums[i] > nums[ma]) {
                ma = i;
            }
            if(nums[i] < nums[mi]) {
                mi = i;
            }
        }
        int left = mi < ma ? mi : ma;
        int right = ma > mi ? ma : mi;
        int res = INT_MAX;
        res = min(res,right+1);
        res = min(res,n-(left));
        res = min(res,left+1 + n-(right));
        return res;
    }
};
auto speed = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();