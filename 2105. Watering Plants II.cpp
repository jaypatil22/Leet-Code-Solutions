class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int res = 0,n = plants.size(),ca = capacityA,cb = capacityB;
        for(int i=0;i<n/2;i++) {
            if(ca < plants[i]) {
                res++;
                ca = capacityA - plants[i];
            } else {
                ca -= plants[i];
            }
        }
        for(int i=n-1;i>=(n+1)/2;i--) {
            if(cb < plants[i]) {
                res++;
                cb = capacityB-plants[i];
            } else {
                cb -= plants[i];
            }
        }
        if(n&1) {
            if(ca > cb) {
                if(ca < plants[n/2]) res++;
            } else {
                if(cb < plants[n/2]) res++;
            }
        }
        return res;
    }
};