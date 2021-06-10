class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        double hr = (double)dist.size();
        if(hr-1 > hour) return -1;
        int l= 1,r= 1e7;
        int res=0; 
        while(l<=r) {
            int mid = l + (r-l)/2;
            double ans = 0;
            for(int i=0;i<dist.size()-1;i++) {
                ans += ceil(float(dist[i])/mid);
            }
            ans += double(dist[dist.size()-1])/mid;
            if(hour-ans < 0) {
                l = mid+1;
            } else {
                res = mid;
                r=mid-1;
            }
        }
        return res ? res : -1;
        
    }
};