class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int mi=nums[0],ma=nums[0];
        for(int a : nums) {
            mi = min(mi,a);
            ma = max(ma,a);
        }
        int n = nums.size();
        // cout << mi << " " << ma <<endl;
        int gap = max((int)ceil((double)(ma-mi)/n-1),1);
        int m = (ma-mi)/gap +1;
        vector<int> minBucket(m,INT_MAX),maxBucket(m,INT_MIN);
        for(int i : nums) {
            if(i==mi || i==ma) continue;
            int idx = (i-mi)/gap;
            minBucket[idx] = min(minBucket[idx],i);
            maxBucket[idx] = max(maxBucket[idx],i);
        }
        int res = INT_MIN;
        int prev=mi;
        for(int i=0;i<m;i++) {
            if(minBucket[i]==INT_MAX && maxBucket[i]==INT_MIN) continue;
            
            res = max(res,minBucket[i]-prev);
            prev = maxBucket[i];
        }
        res = max(res,ma-prev);
        return res;
    }
};