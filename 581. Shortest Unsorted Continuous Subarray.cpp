class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start=-1,end=-1,n=nums.size();
        for(int i=0;i<n-1;i++) {
            if(nums[i] > nums[i+1]) {
                start=i;
                break;
            }
        }
        if(start==-1) return 0;
        for(int i=n-1;i>=0;i--) {
            if(nums[i-1]>nums[i]) {
                end=i;
                break;
            }
        }
        int minValue=INT_MAX,maxValue=INT_MIN;
        for(int i=start;i<=end;i++) {
            minValue=min(minValue,nums[i]);
            maxValue = max(maxValue,nums[i]);
        }
        for(int i=0;i<start;i++) {
            if(nums[i]>minValue) {
                start=i;
                break;
            }
        }
        for(int i=n-1;i>end;i--) {
            if(nums[i]<maxValue) {
                end=i;
                break;
            }
        }
        return end-start+1;
    }
};