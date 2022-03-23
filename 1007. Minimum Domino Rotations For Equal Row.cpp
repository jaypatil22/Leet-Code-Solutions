class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int> cnt,top,bottom;
        unordered_set<int> s;
        int flag = 0;
        for(int i=0;i<tops.size();i++) {
            if(tops[i]==bottoms[i]) {
                cnt[tops[i]]++;
                if(cnt[tops[i]]==tops.size()) {
                    s.insert(tops[i]);
                }
                top[tops[i]]++;
                bottom[tops[i]]++;
            } else {
                cnt[tops[i]]++;
                if(cnt[tops[i]]==tops.size()) {
                    s.insert(tops[i]);
                }
                cnt[bottoms[i]]++;
                if(cnt[bottoms[i]]==tops.size()) {
                    s.insert(bottoms[i]);
                }
                top[tops[i]]++;
                bottom[bottoms[i]]++;
            }
        }
        if(s.size()==0) return -1;
        int res = INT_MAX;
        int n = tops.size();
        for(auto a : s) {
            // cout << a << endl;
            res = min(res,min(n-top[a],n-bottom[a]));
        }
        return res;
    }
};