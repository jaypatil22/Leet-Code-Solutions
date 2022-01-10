class Solution {
public:
    vector<int> res;
    bool st[2005];
    int n;
    bool check(vector<int> &nums,int diff) {
        memset(st,false,sizeof st);
        int cnt = 0, it = 0;
        for(int i=0,j=0,it=0;i<n;) {
            while(i<n && st[i]) i++;
            while(j<n && (st[j] || nums[j]-nums[i]!=diff)) j++;
            if(i<n && j<n) {
                cnt++;
                res[it++] = nums[i] + (diff>>1);
                st[j] = true;
                i++;j++;
            } else {
                break;
            }
        }
        return cnt == (n>>1);
    }
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n = nums.size();
        res.resize(n>>1);
        for(int i=1;i<nums.size();i++) {
            int k = nums[i] - nums[0];
            if(k==0 || k&1) continue;
            if(check(nums,k)) {
                return res;
            }
        }
        return {};
    }
};