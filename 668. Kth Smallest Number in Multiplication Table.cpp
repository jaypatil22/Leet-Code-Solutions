class Solution {
public:
    bool enough(int x,int m, int n, int k) {
        int cnt = 0;
        for(int i=1;i<=m;i++) {
            cnt += min(x/i,n);
        }
        return cnt >= k;
    }
    int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m*n;
        while(lo < hi) {
            int mi = lo + (hi - lo)/2;
            if(!enough(mi,m,n,k)) lo = mi + 1;
            else hi = mi;
        }
        return lo;
    }
};