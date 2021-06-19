class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int res = -1;
        int l = 0,r=removable.size()-1;
        vector<int> map(s.size(),INT_MAX);
        for(int i=0;i<removable.size();i++) {
            map[removable[i]] = i;
        }
        while(l<=r) {
            int mid = l + (r-l)/2,j=0;
            for(int i=0;i<s.size() && j<p.size();i++) {
                if(map[i] > mid && s[i]==p[j]) j++;
            }
            if(j==p.size()) {
                res = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return res+1;
    }
};