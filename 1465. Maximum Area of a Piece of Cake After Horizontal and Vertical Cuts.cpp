class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mh = 0,mw=0,prev=0;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        for(int i=0;i<horizontalCuts.size();i++) {
            if(horizontalCuts[i]-prev > mh) mh = horizontalCuts[i]-prev;
            prev = horizontalCuts[i];
        }
        prev = 0;
        for(int i=0;i<verticalCuts.size();i++) {
            if(verticalCuts[i]-prev > mw) mw = verticalCuts[i]-prev;
            prev = verticalCuts[i];
        }
        const int mod = 1e9+7;
        long long res = ((long long)(mh) * mw)%mod;
        // cout << mh <<  " " << mw << endl;
        return res;
    }
};