class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0)
            return 0;
        int res = 0;
        unordered_map<int, int> s;
        for(int n :nums) s[n]++;

        for(auto a : s) {
            if((!k && a.second > 1) ||(k && s.count(a.first+k)))
                res++;
        }
        return res;
    }
};
