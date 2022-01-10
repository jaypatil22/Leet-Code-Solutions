class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(int a : nums) {
            if(a<0) a*=-1;
            if((int)log10((double)a)%2) res++;
        }
        return res;
    }
};