class Solution {
public:
    int fact(int n) {
        if(n>=12) return INT_MAX;
        int f =1 ;
        for(int i=2;i<=n;i++) f*=i;
        return f;
    }
    string backtrack(int k,vector<int>&nums) {
        int n = nums.size();
        if(n==0 || k>fact(n)) return "";
        int f = fact(n-1);
        int pos = k/f;
        k%=f;
        string ch = to_string(nums[pos]);
        nums.erase(nums.begin()+pos);
        return ch+backtrack(k,nums);
    }
    string getPermutation(int n, int k) {
        vector<int> a;
        for(int i=1;i<=n;i++) a.emplace_back(i);
        return backtrack(k-1,a);
    }
};