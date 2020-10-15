class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        for(int i =0;i<arr1.size();i++) {
            for(int j = 0;j<arr2.size();j++) {
                if(abs(arr1[i]-arr2[j]) <=  d)
                    goto here;
             }
            res += 1;
            here:;
        }
        return res;
    }
};

static const auto speed = [] () {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0;
}();
