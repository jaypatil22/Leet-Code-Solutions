class Solution {
public:
    int countElements(vector<int>& nums) {
        int mi = nums[0], ma = nums[0];
        for(int i=1;i<nums.size();i++) {
            if(nums[i] > ma) ma = nums[i];
            if(nums[i] < mi) mi = nums[i];
        }
        int mic = 0, mac = 0;
        for(int &a : nums) {
            if(a==mi) mic++;
            if(a==ma) mac++;
        }
        if(mic==nums.size()) return 0;
        else return nums.size() - mic - mac;
    }
};