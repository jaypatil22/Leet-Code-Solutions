class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int res=0;
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>1;i--) {
            int h=i-1,l=0;
            while(l<h) {
                if(nums[l]+nums[h]>nums[i]) {
                    res += h-l;
                    h--;
                } else {
                    l++;
                }
            }
            
        }
        return res;
    }
};