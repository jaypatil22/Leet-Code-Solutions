class Solution {
public:
    int check(vector<int> &piles,int b) {
        long long res = 0;
        for(int i : piles) {
            res += ceil((double)i/b);
        }
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 0;
        for(int i : piles) {
            if(i>r) r=i;
        }
        int res = 0;
        while(l <= r) {
            int mid = l + (r-l)/2;
            long long c = check(piles,mid);
            // cout << c << " " << mid << endl;
            if(c <= h) {
                r = mid -1;
                res = mid;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
auto speedup = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();