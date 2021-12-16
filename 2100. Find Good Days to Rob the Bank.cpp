class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> a(n),b(n);
        a[0] = 0;
        b[n-1] = 0;
        for(int i=1;i<security.size();i++) {
            if(security[i] <= security[i-1]) {
                a[i] = a[i-1]+1;
            } else {
                a[i] = 0;
            }
        }
        for(int i=n-2;i>=0;i--) {
            if(security[i] <= security[i+1]) {
                b[i] = b[i+1] + 1;
            } else {
                b[i] = 0;
            }
        }
        vector<int> res;
        for(int i=0;i<n;i++) {
            if(a[i] >= time && b[i] >= time) res.push_back(i);
        }
        return res;
    }
};