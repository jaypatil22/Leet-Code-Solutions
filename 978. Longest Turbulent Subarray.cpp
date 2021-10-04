class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int res = 1;
        int start = 0;
        for(int i=1;i<n;i++) {
            long long c = arr[i] - arr[i-1];
            if(c == 0) {
                start = i;
            } else if(i == n-1 || (c*(arr[i] - arr[i+1])) <= 0) {
                res = max(res, i - start + 1);
                start = i;
            }
        }
        return res;
    }
};