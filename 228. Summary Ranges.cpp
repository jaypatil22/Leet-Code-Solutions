class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0;
        vector<string> res;
        while(i<nums.size()) {
            int start = nums[i];
            while(i+1<nums.size() && nums[i+1]<=nums[i]+1) {
                i++;
            }
            int end = nums[i];
            if(start == end) {
                res.push_back(to_string(start));
            } else {
                string a = to_string(start) + "->" + to_string(end);
                res.push_back(a);
            }
            i++;
        }
        return res;
    }
};