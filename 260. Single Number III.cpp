class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xr = 0;
        for(int a : nums) {
            xr ^= a;
        }
        long long rsb = (long long)xr & -(long long)xr;
        bitset<32> mx(-xr);
        //cout << xr << " " << mx << " " << rsb << endl;
        int n = 0;
        for(int a : nums) {
            if(rsb & a) {
                n ^= a;
            }
        }
        int a = n, b = xr^n;
        return {a,b};
    }
};