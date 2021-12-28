class Solution {
public:
    int helper(vector<int> &v) {
        vector<int> sub;
        for(int i=0;i<v.size();i++) {
            int x = v[i];
            if(sub.empty() || sub.back() <= x) {
                sub.push_back(x);
            } else {
                int idx = upper_bound(sub.begin(),sub.end(),x) - sub.begin();
                sub[idx] = x;
            }
        }
        return v.size() - sub.size();
    }
    int kIncreasing(vector<int>& arr, int k) {
        int res = 0;
        for(int i=0;i<k;i++) {
            vector<int> v;
            for(int j=i;j<arr.size();j+=k) {
                v.push_back(arr[j]);
            }
            res += helper(v);
        }
        return res;
    }
};