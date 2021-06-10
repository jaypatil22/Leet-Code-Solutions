class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<int> inx(n);
        for(int i=0;i<n;i++) {
            inx[i] = i;
        }
        sort(inx.begin(),inx.end(),[&](const int l,const int r) { return efficiency[l] > efficiency[r]; });
        priority_queue<int> pq;
        long long res = 0,sum=0;
        for(int i=0;i<n;i++) {
            int le = efficiency[inx[i]];
            sum += speed[inx[i]];
            if(pq.size() > k-1) {
                sum-=-pq.top();pq.pop();
            }
            pq.push(-speed[inx[i]]);
            res =  max(res,le*sum);
        }
        const int mod = 1e9+7;
        return res%mod;
    }
};