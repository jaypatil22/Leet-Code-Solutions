class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()*6<nums1.size() || nums1.size()*6<nums2.size()) 
            return -1;
        int res=0;
        int sum1 = accumulate(nums1.begin(),nums1.end(),0),sum2 = accumulate(nums2.begin(),nums2.end(),0);
        if(sum1>sum2)
            swap(nums1,nums2);
        int diff=abs(sum2-sum1);
        vector<int> cnt(6,0);
        for(int c : nums1) {
            cnt[6-c]++;
        }
        for(int c:nums2) {
            cnt[c-1]++;
        }
        for(int i=5;i>0 && diff>=0;i--) {
            int take = min(cnt[i],diff/i+(diff%i!=0));
            diff -= i*take;
            res += take;
        }
        return res;
    }
};