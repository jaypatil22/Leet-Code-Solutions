class Solution {
public:
    int specialArray(vector<int>& nums) {
        int res = -1;
        sort(nums.begin(),nums.end());
        int n = nums[nums.size()-1];
        int pos = 0;
        for(int i =0;i<=n;i++) {
            while(nums[pos] < i)
                pos++;
            int a = nums.size()-(pos);
            if(a == i)
                return a;
        }
        return res;
    }
};
