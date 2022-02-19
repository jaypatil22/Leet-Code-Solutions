class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int,int> s;
        int res = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                s[nums1[i]+nums2[j]]++;
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(s.find(0-nums3[i]-nums4[j])!=s.end()) res += s[0-nums3[i]-nums4[j]];
            }
        }
        return res;
    }
};