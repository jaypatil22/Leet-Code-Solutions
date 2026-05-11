class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for(int i : nums) {
            vector<int> inter;
            while(i) {
                int d = i%10;
                i = i/10;
                inter.push_back(d);
            }
            for(int j=inter.size()-1;j>=0;j--) {
                res.push_back(inter[j]);
            }
        }
        return res;
    }
};